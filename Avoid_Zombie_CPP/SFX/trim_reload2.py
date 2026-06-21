"""reload2.mp3 -> 0.1~2.75초 구간만 잘라 WAV로 변환 (imageio-ffmpeg 번들 ffmpeg 사용)."""
import subprocess
import wave
import imageio_ffmpeg

FF = imageio_ffmpeg.get_ffmpeg_exe()
SFX = r"C:\Unreal Cpp Project\Avoid_Zombie_CPP\SFX"
SRC = f"{SFX}\\reload2.mp3"
DST = f"{SFX}\\reload2_trim.wav"

START = 0.10
END = 2.75
DUR = END - START               # 2.65s
FADE_OUT_ST = DUR - 0.04        # 끝 40ms 페이드아웃

cmd = [
    FF, "-y",
    "-ss", str(START), "-t", str(DUR), "-i", SRC,
    "-af", f"afade=t=in:st=0:d=0.005,afade=t=out:st={FADE_OUT_ST}:d=0.04",
    "-ar", "48000", "-ac", "2", "-c:a", "pcm_s24le",
    DST,
]
subprocess.run(cmd, check=True, capture_output=True)

w = wave.open(DST, "rb")
print(f"OK -> {DST}")
print(f"  dur={w.getnframes()/w.getframerate():.3f}s  rate={w.getframerate()}  "
      f"ch={w.getnchannels()}  {w.getsampwidth()*8}-bit")
w.close()
