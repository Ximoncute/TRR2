import numpy as np
import matplotlib.pyplot as plt

# Cấu hình để hiển thị chữ đẹp, dùng LaTeX
plt.rcParams.update({
    "text.usetex": True,
    "font.family": "serif",
    "font.size": 14,
    "figure.dpi": 300,  # độ phân giải cao
})

theta = np.linspace(0, 2 * np.pi, 1000)

# Ba điện áp pha
ua = np.sin(theta)
ub = np.sin(theta - 2 * np.pi / 3)
uc = np.sin(theta + 2 * np.pi / 3)

# Điện áp sau chỉnh lưu nửa chu kỳ
ud = np.maximum.reduce([ua, ub, uc])

# Vẽ biểu đồ
plt.figure(figsize=(10, 6))
plt.plot(theta, ua, 'r', label=r'$u_a$')
plt.plot(theta, ub, 'g', label=r'$u_b$')
plt.plot(theta, uc, 'b', label=r'$u_c$')
plt.plot(theta, ud, 'k', linewidth=2, label=r'$u_d = \max(u_a, u_b, u_c)$')

# Ghi chú các điểm M, N, L, P
for t, label in zip([np.pi/6, 5*np.pi/6, np.pi, 2*np.pi], ['M', 'N', 'L', 'P']):
    plt.axvline(x=t, color='gray', linestyle='--', linewidth=0.7)
    plt.text(t, 1.05, label, ha='center', fontsize=12)

# Ghi các điểm θ₁, θ₂, θ₃, θ₄
theta_marks = [0.5, 2.4, 4.3, 6.1]
for i, t in enumerate(theta_marks, start=1):
    plt.axvline(x=t, color='gray', linestyle=':', linewidth=0.7)
    plt.text(t, -1.3, rf'$\theta_{i}$', ha='center', fontsize=12)

# Nhãn trục
plt.xlabel(r'$\theta$', fontsize=14)
plt.ylabel(r'$u$', fontsize=14)
plt.title(r'\textbf{Biểu đồ điện áp 3 pha và điện áp chỉnh lưu}', fontsize=16)
plt.grid(True)
plt.legend()
plt.ylim(-1.5, 1.2)
plt.xlim(0, 2 * np.pi)

# Lưu hình độ phân giải cao
plt.tight_layout()
plt.savefig("dien_ap_3_pha_chinh_luu.png", dpi=600)  # Xuất ảnh PNG nét cao
plt.show()
