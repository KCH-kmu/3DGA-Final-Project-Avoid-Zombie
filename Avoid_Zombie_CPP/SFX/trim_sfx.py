"""SFX 트리머 — 원본 WAV을 지정 구간만 남기고 잘라 _trim.wav로 저장.
24-bit/스테레오 보존(wave 모듈은 프레임 단위 raw 바이트 처리), 클릭 방지용 짧은 페이드 포함.
"""
import wave

SFX_DIR = r"C:\Unreal Cpp Project\Avoid_Zombie_CPP\SFX"

# (이름, 시작초, 끝초, 페이드인초, 페이드아웃초)
JOBS = [
    ("gunfire", 0.08, 0.60, 0.003, 0.030),
    ("reload",  0.40, 1.60, 0.005, 0.040),
]


def apply_gain(buf, frame, ch, sw, gain):
    """buf의 frame번째 프레임 모든 채널에 gain(0~1)을 곱한다 (24-bit signed LE 안전)."""
    fsz = sw * ch
    for c in range(ch):
        off = frame * fsz + c * sw
        val = int.from_bytes(buf[off:off + sw], "little", signed=True)
        val = int(val * gain)
        buf[off:off + sw] = val.to_bytes(sw, "little", signed=True)


def trim(name, start, end, fin, fout):
    src = f"{SFX_DIR}\\{name}.wav"
    dst = f"{SFX_DIR}\\{name}_trim.wav"

    w = wave.open(src, "rb")
    fr, ch, sw, n = w.getframerate(), w.getnchannels(), w.getsampwidth(), w.getnframes()
    s = max(0, int(start * fr))
    e = min(n, int(end * fr))
    w.setpos(s)
    raw = bytearray(w.readframes(e - s))
    w.close()

    total = len(raw) // (sw * ch)
    fi = min(int(fin * fr), total)
    fo = min(int(fout * fr), total)

    for f in range(fi):                       # 페이드 인
        apply_gain(raw, f, ch, sw, (f + 1) / fi)
    for j in range(fo):                       # 페이드 아웃
        apply_gain(raw, total - fo + j, ch, sw, 1.0 - (j + 1) / fo)

    out = wave.open(dst, "wb")
    out.setnchannels(ch)
    out.setsampwidth(sw)
    out.setframerate(fr)
    out.writeframes(bytes(raw))
    out.close()

    print(f"{name}: {start}~{end}s -> {dst}  (dur={total / fr:.3f}s, ch={ch}, {sw*8}-bit, {fr}Hz)")


for job in JOBS:
    trim(*job)
