#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Quaternion { // 顺便把类名改成了更标准的 Quaternion
private:
	double w, x, y, z; // 标准的四元数命名：w是实部，x,y,z是虚部

public:
	// 构造函数（使用 double 类型，避免小数被截断）
	Quaternion(double w = 0.0, double x = 0.0, double y = 0.0, double z = 0.0)
		: w(w), x(x), y(y), z(z) {}

	// Getter 函数
	double getW() const { return w; }
	double getX() const { return x; }
	double getY() const { return y; }
	double getZ() const { return z; }

	double norm_s()const {
		return w * w + x * x + y * y + z * z;
	}
	double norm()const {
		return sqrt(norm_s());
	}
	Quaternion normalized()const {
		double n = norm();
		if (n == 0)return Quaternion(0, 0, 0, 0);
		return Quaternion(w / n, x / n, y / n, z / n);
	}


	// 重载加法 (+)
	friend Quaternion operator +(const Quaternion& m, const Quaternion& n) {
		return Quaternion(m.w + n.w, m.x + n.x, m.y + n.y, m.z + n.z);
	}

	// 重载减法 (-)
	friend Quaternion operator -(const Quaternion& m, const Quaternion& n) {
		return Quaternion(m.w - n.w, m.x - n.x, m.y - n.y, m.z - n.z);
	}

	// 重载乘法 (*)
	friend Quaternion operator *(const Quaternion& m, const Quaternion& n) {
		double resW = m.w * n.w - m.x * n.x - m.y * n.y - m.z * n.z;
		double resX = m.w * n.x + m.x * n.w + m.y * n.z - m.z * n.y;
		double resY = m.w * n.y - m.x * n.z + m.y * n.w + m.z * n.x;
		double resZ = m.w * n.z + m.x * n.y - m.y * n.x + m.z * n.w;
		return Quaternion(resW, resX, resY, resZ);
	}

	// 重载除法 (/)
	friend Quaternion operator /(const Quaternion& m, const Quaternion& n) {
		double norm_sq = n.norm_s();
		if (norm_sq == 0.0) {
			cout << "cuowu,bunengwei0" << endl;
			return Quaternion(0, 0, 0, 0);
		}
		Quaternion n_inverse(n.w / norm_sq, -n.x / norm_sq, -n.y / norm_sq, -n.z / norm_sq);
		return m * n_inverse;
	}
	friend ostream& operator <<(ostream& out, const Quaternion& s) {
		out << fixed << setprecision(4); // 保留4位小数，看起来更整洁
		out << "(" << s.w << ", " << s.x << ", " << s.y << ", " << s.z << ")";
		return out;
	}
};
int main() {
	Quaternion s1(1, 5, 6, 7);
	Quaternion s2(8, 5, 1, 3);
	Quaternion s3;
	s3 = s1 + s2;
	cout << s3 << endl;
	cout << s1 / s2 << endl;
	return 0;
}