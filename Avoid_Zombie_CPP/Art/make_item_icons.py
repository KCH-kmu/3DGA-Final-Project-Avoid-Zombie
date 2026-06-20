# -*- coding: utf-8 -*-
"""Generate item pickup UI icons for Avoid_Zombie_CPP (WBP_ZombieHUD item box).
Transparent background, theme-colored gradient symbol only.
Pure-Pillow, supersampled 4x for crisp anti-aliasing. 512x512 RGBA PNG.
"""
import os, math
from PIL import Image, ImageDraw, ImageChops, ImageFilter

OUT = os.path.dirname(os.path.abspath(__file__))
SIZE = 512
SS = 4
S = SIZE * SS
CX = CY = S / 2.0


def vgrad(top, bot):
    """Vertical gradient RGB image, top->bot."""
    col = Image.new("RGB", (1, S))
    px = col.load()
    for y in range(S):
        t = y / (S - 1)
        px[0, y] = tuple(int(top[i] + (bot[i] - top[i]) * t) for i in range(3))
    return col.resize((S, S))


# ---------- symbol drawing (drawn onto an L mask with fill=255) ----------

def sym_cross(d, c):
    t = S * 0.150
    L = S * 0.58
    rr = t * 0.30
    d.rounded_rectangle([CX - L / 2, CY - t / 2, CX + L / 2, CY + t / 2], radius=rr, fill=c)
    d.rounded_rectangle([CX - t / 2, CY - L / 2, CX + t / 2, CY + L / 2], radius=rr, fill=c)


def sym_snowflake(d, c):
    Rspoke = S * 0.32
    w = max(2, int(S * 0.040))
    for k in range(6):
        ang = math.radians(60 * k - 90)
        tx = CX + Rspoke * math.cos(ang)
        ty = CY + Rspoke * math.sin(ang)
        d.line([CX, CY, tx, ty], fill=c, width=w)
        d.ellipse([tx - w / 2, ty - w / 2, tx + w / 2, ty + w / 2], fill=c)
        for frac in (0.50, 0.78):
            bx = CX + Rspoke * frac * math.cos(ang)
            by = CY + Rspoke * frac * math.sin(ang)
            blen = Rspoke * 0.23
            for s in (+1, -1):
                ba = ang + s * math.radians(60)
                ex = bx + blen * math.cos(ba)
                ey = by + blen * math.sin(ba)
                d.line([bx, by, ex, ey], fill=c, width=w)
                d.ellipse([ex - w / 2, ey - w / 2, ex + w / 2, ey + w / 2], fill=c)
    d.ellipse([CX - w * 0.7, CY - w * 0.7, CX + w * 0.7, CY + w * 0.7], fill=c)


def sym_lightning(d, c, scale=1.0):
    pts = [(0.50, 0.00), (0.00, 0.60), (0.35, 0.60),
           (0.15, 1.00), (0.85, 0.45), (0.50, 0.45)]
    h = S * 0.30 * scale
    w = h * 0.62
    ox = CX - w / 2
    oy = CY - h / 2
    d.polygon([(ox + px * w, oy + py * h) for px, py in pts], fill=c)


def sym_reload_lightning(d, c):
    """Two rotating arrows (refresh) + lightning core. Arrowheads sit exactly
    on each arc endpoint, pointing along the clockwise tangent."""
    rad = S * 0.235
    aw = int(S * 0.070)
    bbox = [CX - rad, CY - rad, CX + rad, CY + rad]
    # PIL arc: 0deg = 3 o'clock, angle increases clockwise (y is down).
    # Two ~135deg arcs, point-symmetric, with 45deg gaps for the heads.
    d.arc(bbox, 30, 165, fill=c, width=aw)
    d.arc(bbox, 210, 345, fill=c, width=aw)

    def head(theta_deg):
        th = math.radians(theta_deg)
        px = CX + rad * math.cos(th)
        py = CY + rad * math.sin(th)
        tx, ty = -math.sin(th), math.cos(th)      # clockwise tangent (unit)
        ppx, ppy = -ty, tx                         # perpendicular (unit)
        h = aw * 2.3                                # head length
        hw = aw * 1.45                             # head half-width
        tip = (px + tx * h * 0.6, py + ty * h * 0.6)
        bc = (px - tx * h * 0.4, py - ty * h * 0.4)
        c1 = (bc[0] + ppx * hw, bc[1] + ppy * hw)
        c2 = (bc[0] - ppx * hw, bc[1] - ppy * hw)
        d.polygon([tip, c1, c2], fill=c)

    head(165)
    head(345)
    sym_lightning(d, c, scale=0.80)


# ---------- compose one icon (transparent bg, colored gradient symbol) ----------

def make(name, top, bot, sym_fn):
    # 1. build symbol coverage mask
    mask = Image.new("L", (S, S), 0)
    sym_fn(ImageDraw.Draw(mask), 255)

    canvas = Image.new("RGBA", (S, S), (0, 0, 0, 0))

    # 2. soft drop shadow (invisible on pure black, adds depth elsewhere)
    sh = Image.new("RGBA", (S, S), (0, 0, 0, 0))
    sh.paste((0, 0, 0, 150), (0, 0), mask)
    sh = sh.filter(ImageFilter.GaussianBlur(S * 0.014))
    sh = ImageChops.offset(sh, 0, int(S * 0.012))
    canvas.alpha_composite(sh)

    # 3. gradient-filled symbol
    fill = vgrad(top, bot).convert("RGBA")
    fill.putalpha(mask)
    canvas.alpha_composite(fill)

    out = canvas.resize((SIZE, SIZE), Image.LANCZOS)
    out.save(os.path.join(OUT, name))
    print("saved", name)
    return out


icons = [
    ("T_Item_Health.png",       (0x8C, 0xF0, 0x96), (0x27, 0xB0, 0x45), sym_cross),
    ("T_Item_ReloadSpeed.png",  (0xFF, 0xD6, 0x6B), (0xF2, 0x86, 0x16), sym_reload_lightning),
    ("T_Item_ZombieFreeze.png", (0xA6, 0xEF, 0xFF), (0x29, 0xB6, 0xEE), sym_snowflake),
]

made = [make(*ic) for ic in icons]

# preview on a black rounded item-box (simulates WBP_ZombieHUD placement)
pad, box = 28, SIZE // 2 + 40
sheet = Image.new("RGBA", (box * 3 + pad * 4, box + pad * 2), (24, 25, 28, 255))
ds = ImageDraw.Draw(sheet)
for i, im in enumerate(made):
    x = pad + i * (box + pad)
    y = pad
    ds.rounded_rectangle([x, y, x + box, y + box], radius=24, fill=(0, 0, 0, 255),
                         outline=(70, 72, 78, 255), width=3)
    icon = im.resize((box - 24, box - 24), Image.LANCZOS)
    sheet.alpha_composite(icon, (x + 12, y + 12))
sheet.save(os.path.join(OUT, "_preview_on_black.png"))
print("done")
