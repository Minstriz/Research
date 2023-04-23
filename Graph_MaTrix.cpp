#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
const int MAX = 20;
using namespace std;

struct MaTranKe {
	int mtk[MAX][MAX];
	int n;
};
struct CanhDoThi {
	int dinhdau;
	int dinhcuoi;
	int trongso;
};
int docMaTran(MaTranKe& a, const char* dothi) {
	FILE* fp;
	fp = fopen(dothi, "r");
	if (fp != NULL) {
		fscanf(fp, "%d", &a.n);
		for (int i = 0; i < a.n; i++)
			for (int j = 0; j < a.n; j++)
				fscanf(fp, "%d", &a.mtk[i][j]);
		fclose(fp);
		return 1;
	}
	return 0;
}
void InMaTran(MaTranKe a) {
	for (int i = 0; i < a.n; i++) {
		cout << "\n";
		for (int j = 0; j < a.n; j++)
		{
			cout << "\t" << a.mtk[i][j];
		}
	}
}
void soDinhDoThi(MaTranKe a) {
	cout << "\nSo dinh do thi: " << a.n;
}
void soCanhDoThiVoHuong(MaTranKe a) {
	int canh = 0;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (a.mtk[i][j] != 0)
				canh++;
		}
	}
	int Canh = canh / 2;
	cout << "\nSo canh do thi: " << Canh;
}
void soCanhDoThiCoHuong(MaTranKe a) {
	int canh = 0;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (a.mtk[i][j] != 0)
				canh++;
		}
	}
	cout << "\nSo canh do thi: " << canh;
}
void demSoBacDinhU(MaTranKe a, int u) {
	int bac = 0;
	for (int i = 0; i < a.n; i++) {
		if (a.mtk[u][i] != 0)
			bac++;
	}
	cout << "\nBac cua dinh u: " << bac;
}
void demBacVaoCoHuong(MaTranKe a, int u) {
	int bac = 0;
	for (int i = 0; i < a.n; i++) {
		if (a.mtk[u][i] != 0)
			bac++;
	}
	cout << "\nSo bac vao: " << bac;
}
void demBacRaCoHuong(MaTranKe a, int u) {
	int bac = 0;
	for (int i = 0; i < a.n; i++) {
		if (a.mtk[i][u] != 0)
			bac++;
	}
	cout << "\nSo bac ra: " << bac;
}
//canh co trong so cao nhat
void canhCoTrongSoLonNhat(MaTranKe a) {
	int max = 1;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (a.mtk[i][j] != 0) {
				max = a.mtk[i][j];
				break;
			}
		}
	}
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (a.mtk[i][j] > max)
				max = a.mtk[i][j];
		}
	}
	cout << "\nCanh co trong so lon nhat: " << max;
}
//Canh co trong so nho nhat
void canhCoTrongSoNhoNhat(MaTranKe a) {
	int min = 0;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (a.mtk[i][j] != 0) {
				min = a.mtk[i][j];
				break;
			}
		}
	}
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (a.mtk[i][j] < min && a.mtk[i][j] != 0) {
				min = a.mtk[i][j];
			}
		}
	}
	cout << "\nCanh co trong so nho nhat: " << min;
}
void traVeCapDinhLonNhat(MaTranKe a) {
	int max = 1;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (a.mtk[i][j] != 0) {
				max = a.mtk[i][j];
				break;
			}
		}
	}
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (a.mtk[i][j] > max)
				max = a.mtk[i][j];
		}
	}
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (a.mtk[i][j] == max)
			{
				cout << "\n[" << i << "]"; cout << "[" << j << "]";
				break;
			}
		}
	}
}
//int traVeCapDinhLonNhat(MaTranKe a, int &u, int &v) {
//	int max = 1;
//	for (int i = 0; i < a.n; i++) {
//		for (int j = 0; j < a.n; j++) {
//			if (a.mtk[i][j] != 0) {
//				max = a.mtk[i][j];
//				u = i;
//				v = j;
//				break;
//			}
//		}
//	}
//	for (int i = 0; i < a.n; i++) {
//		for (int j = 0; j < a.n; j++) {
//			if (a.mtk[i][j] > max || a.mtk[i][j]!=0) {
//				max = a.mtk[i][j];
//				u = i;
//				v = j;
//			}
//		}
//	}
//	return max;
//}
void main() {
	MaTranKe a;
	docMaTran(a, "dothi.txt");
	/*docMaTran(a, "text.txt");*/
	//docMaTran(a, "text2.txt");
	InMaTran(a);
	//Dinh cua do thi
	soDinhDoThi(a);
	//Canh cua do thi co huong
	soCanhDoThiCoHuong(a);
	//Canh cua do thi vo huong
	soCanhDoThiVoHuong(a);
	//Bac cua dinh U
	int u;
	cout << "\nNhap U de tim so bac:"; cin >> u;
	demSoBacDinhU(a, u);
	//So bac vao co huong
	demBacVaoCoHuong(a, u);
	//So bac ra co huong
	demBacRaCoHuong(a, u);
	//Canh co trong so lon nhat
	canhCoTrongSoLonNhat(a);
	//Canh co trong so lon nhat
	canhCoTrongSoNhoNhat(a);
	//tra ve cap dinh lon nhat
	//int u = 0;
	//int v=0;
	cout << "\nCap dinh co trong so lon nhat:";
	traVeCapDinhLonNhat(a);
	//cout << "\n[" << u << "]"; cout << "\n[" << v << "]";
}