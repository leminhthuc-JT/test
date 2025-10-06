#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Câu 1
struct TIME
{
	int day;
	int month;
	int year;
};

//Câu 1
struct khohang
{
	char makho[10];
	char tenkho[50];
	char diadiem[20];
	float taitrong;
	char loai[20];
	TIME nhapkho;
	TIME xuatkho;
	float taitrongnhap;
};

struct SNode
{
	khohang data;
	SNode* Next;
};

struct Slist
{
	SNode* Head;
	SNode* Tail;
};

//Tạo nút
SNode* create_SNode(khohang& a)
{
	SNode* p = new SNode;
	if (p == NULL)
	{
		printf("\nKhong du bo nho de cap phat!");
		return NULL;
	}
	else
	{
		p->data = a;
		p->Next = NULL;
		return p;
	}
}

//Khởi tạo
void initSlist(Slist& sl)
{
	sl.Head = NULL;
	sl.Tail = NULL;
}

//Kiểm tra rỗng
bool isEmpty(Slist sl)
{
	if (sl.Head == NULL)
		return true;
	else
		return false;
}

//Câu 3
void them_dau(Slist& sl, SNode* p)
{
	if (p == NULL) {
		return;
	}
	else
	{
		if (isEmpty(sl) == true)
		{
			sl.Head = sl.Tail = p;
		}
		else
		{
			p->Next = sl.Head;
			sl.Head = p;
		}
	}
}

//Câu 3
void them_cuoi(Slist& sl, SNode* p)
{
	if (p == NULL)
	{
		return;
	}
	else
	{
		if (isEmpty(sl) == true)
		{
			sl.Head = sl.Tail = p;
		}
		else
		{
			sl.Tail->Next = p;
			sl.Tail = p;
		}
	}
}

//Câu 3
void thempsauq(Slist& sl, SNode* p, SNode* q)
{
	if (p == NULL || q == NULL)
	{
		return;
	}
	else
	{
		if (q == sl.Tail)
		{
			them_cuoi(sl, p);
		}
		else
		{
			p->Next = q->Next;
			q->Next = p;
		}
	}
}

//Câu 3
void xoa_dau(Slist& sl)
{
	SNode* tmp = sl.Head;
	if (isEmpty(sl) == true)
	{
		return;
	}
	else
	{
		if (sl.Head == sl.Tail)
		{
			sl.Head = sl.Tail = NULL;
		}
		else
		{
			sl.Head = sl.Head->Next;
		}
		delete(tmp);
	}
}

//Câu 3
void xoa_cuoi(Slist& sl)
{
	SNode* p = sl.Head;
	if (isEmpty(sl) == true)
	{
		return;
	}
	else
	{
		SNode* tmp = sl.Tail;
		if (sl.Head == sl.Tail)
		{
			sl.Head = sl.Tail = NULL;
		}
		else
		{
			while (p->Next != sl.Tail)
			{
				p = p->Next;
			}
			p->Next = NULL;
			sl.Tail = p;
		}
		delete(tmp);
	}
}

//Tìm x
SNode* timx(Slist sl, khohang x)
{
	if (isEmpty(sl) == true)
	{
		return NULL;
	}
	else
	{
		SNode* p = sl.Head;
		while (p != NULL && strcmp(x.makho, p->data.makho) != 0) {
			p = p->Next;
		}
		return p;
	}
}

//Câu 3
void xoa_p(Slist& sl, SNode* p)
{
	SNode* tmp = sl.Head;
	if (isEmpty(sl) == true)
	{
		return;
	}
	else
	{
		if (p == sl.Head)
		{
			xoa_dau(sl);
		}
		else if (p == sl.Tail)
		{
			xoa_cuoi(sl);
		}
		else
		{
			while (tmp->Next != p)
			{
				tmp = tmp->Next;
			}
			tmp->Next = p->Next;
			p->Next = NULL;
			delete(p);
		}
	}
}

//Câu 2
void Nhaptt(khohang m[], int& n)
{
	printf("\nNhap vao so luong kho hang: ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		puts("\nNhap vao ma kho hang: ");
		getchar();
		gets_s(m[i].makho);
		puts("\nNhap vao ten kho hang: ");
		gets_s(m[i].tenkho);
		puts("\nNhap dia diem kho hang: ");
		gets_s(m[i].diadiem);
		printf("\nNhap tai trong kho hang: ");
		scanf_s("%f", &m[i].taitrong);
		getchar();
		puts("\nNhap vap loai kho hang: ");
		gets_s(m[i].loai);
		printf("\nNhap lan luot ngay thang nam nhap kho: ");
		scanf_s("%d %d %d", &m[i].nhapkho.day, &m[i].nhapkho.month, &m[i].nhapkho.year);
		printf("\nNhap lan luot ngay thang nam xuat kho: ");
		scanf_s("%d %d %d", &m[i].xuatkho.day, &m[i].xuatkho.month, &m[i].xuatkho.year);
		printf("\nNhap vao tai trong hang nhap kho: ");
		scanf_s("%f", &m[i].taitrongnhap);
	}
}

void Nhap(khohang& a)
{
	puts("\nNhap vao ma kho hang: ");
	getchar();
	gets_s(a.makho);
	puts("\nNhap vao ten kho hang: ");
	gets_s(a.tenkho);
	puts("\nNhap dia diem kho hang: ");
	gets_s(a.diadiem);
	printf("\nNhap tai trong kho hang: ");
	scanf_s("%f", &a.taitrong);
	getchar();
	puts("\nNhap vap loai kho hang: ");
	gets_s(a.loai);
	printf("\nNhap lan luot ngay thang nam nhap kho: ");
	scanf_s("%d %d %d", &a.nhapkho.day, &a.nhapkho.month, &a.nhapkho.year);
	printf("\nNhap lan luot ngay thang nam xuat kho: ");
	scanf_s("%d %d %d", &a.xuatkho.day, &a.xuatkho.month, &a.xuatkho.year);
	printf("\nNhap vao tai trong hang nhap kho: ");
	scanf_s("%f", &a.taitrongnhap);
}

//hoán vị
void hoanvi(khohang& a, khohang& b)
{
	khohang c = a;
	a = b;
	b = c;
}

//Câu 4
void sapxep(Slist sl) {
	SNode* tmp = sl.Head;
	if (sl.Head == NULL) return;
	while (tmp != NULL) {
		SNode* netmp = tmp->Next;
		while (netmp != NULL) {
			if (tmp->data.taitrong > netmp->data.taitrong) {
				hoanvi(tmp->data, netmp->data);
			}
			netmp = netmp->Next;
		}
		tmp = tmp->Next;
	}
}

//Xuất thông tin 
void Xuattt(khohang a) {
	printf("\n|  \t%s\t", a.makho);
	printf("|  %s\t", a.tenkho);
	printf("|  %s\t", a.diadiem);
	printf("|\t%.2f\t", a.taitrong);
	printf("|   %s\t", a.loai);
	printf("|  %d/%d/%d\t", a.nhapkho.day, a.nhapkho.month, a.nhapkho.year);
	printf("|  %d/%d/%d\t", a.xuatkho.day, a.xuatkho.month, a.xuatkho.year);
	printf("|\t\t%.2f\t\t|", a.taitrongnhap);
}

//In thông tin
void in(Slist& sl, khohang m[], int n)
{
	for (int i = 0; i < n; i++)
	{
		SNode* p = create_SNode(m[i]);
		them_cuoi(sl, p);
	}
}

//Câu 2
void docfile(const char* filename, khohang m[], int& n)
{
	FILE* f;
	errno_t file = fopen_s(&f, filename, "rt");
	if (file == 0 && f != NULL) {
		fscanf_s(f, "%d", &n);
		for (int i = 0; i < n; i++)
		{
			fflush(stdin);
			fscanf_s(f, "%s", &m[i].makho, _countof(m[i].makho));
			fscanf_s(f, "%s", &m[i].tenkho, _countof(m[i].tenkho));
			fscanf_s(f, "%s", &m[i].diadiem, _countof(m[i].diadiem));
			fscanf_s(f, "%f", &m[i].taitrong);
			fscanf_s(f, "%s", &m[i].loai, _countof(m[i].loai));
			fscanf_s(f, "%d %d %d", &m[i].nhapkho.day, &m[i].nhapkho.month, &m[i].nhapkho.year);
			fscanf_s(f, "%d %d %d", &m[i].xuatkho.day, &m[i].xuatkho.month, &m[i].xuatkho.year);
			fscanf_s(f, "%f", &m[i].taitrongnhap);
		}
		fclose(f);
	}
}

//Câu 5
void them_x(Slist& sl, khohang& a)
{
	SNode* p = sl.Head;
	SNode* q = NULL;
	while (p != NULL && p->data.taitrong < a.taitrong)
	{
		q = p;
		p = p->Next;
	}
	SNode* tmp = create_SNode(a);
	if (p == sl.Head) {
		them_dau(sl, tmp);
	}

	else if (p == NULL) {
		q->Next = tmp->Next;
		q->Next = tmp;
	}
	else {
		q->Next = tmp->Next;
		q->Next = tmp;
		tmp->Next = p;
	}
}

//Câu 6
void find_date(Slist sl, khohang& x)
{
	int count = 0;
	printf("\n\nNhap vao thang va nam nhap kho cua kho hang can tim: ");
	scanf_s("%d %d", &x.nhapkho.month, &x.nhapkho.year);
	if (sl.Head == NULL) return;
	else {
		printf("\n\nCac kho hang duoc nhap vao thang %d nam %d la:", x.nhapkho.month, x.nhapkho.year);
		SNode* tmp = sl.Head;
		while (tmp != NULL)
		{
			if ((x.nhapkho.month == tmp->data.nhapkho.month) && (x.nhapkho.year == tmp->data.nhapkho.year)) {
				Xuattt(tmp->data);
				count++;
			}
			tmp = tmp->Next;
		}
		if (count == 0)
			printf("\nKhong tim thay kho hang duoc nhap vao thang %d nam %d!", x.nhapkho.month, x.nhapkho.year);
	}
}

//Câu 7
void find_trong(Slist sl)
{
	int count = 0;
	if (sl.Head == NULL) return;
	else {
		printf("\n\nCac kho hang con trong la: ");
		SNode* tmp = sl.Head;
		while (tmp != NULL)
		{
			if (tmp->data.taitrong > tmp->data.taitrongnhap) {
				Xuattt(tmp->data);
				count++;
			}
			tmp = tmp->Next;
		}
		if (count == 0)
			printf("\nKhong tim thay kho hang con trong!");
	}
}

//Câu 8
void find_loai(Slist sl)
{
	int count = 0;
	if (sl.Head == NULL) return;
	else {
		printf("\n\nCac kho chua hang dong lanh la:");
		SNode* tmp = sl.Head;
		while (tmp != NULL)
		{
			if (strcmp("Dong_lanh", tmp->data.loai) == 0) {
				Xuattt(tmp->data);
				count++;
			}
			tmp = tmp->Next;
		}
		if (count == 0)
			printf("\nKhong tim thay kho chua hang dong lanh!");
	}
}

//Câu 9
void gpataitrong(Slist sl)
{
	float sumtaitrong = 0;
	int count = 0;
	if (sl.Head == NULL) return;
	else
	{
		SNode* tmp = sl.Head;
		while (tmp != NULL)
		{
			while (strcmp("Dong_Nai", tmp->data.diadiem) == 0)
			{
				count++;
				sumtaitrong += tmp->data.taitrong;
				break;
			}
			tmp = tmp->Next;
		}
		printf("\n\nTai trong trung binh cua cac kho hang o Dong Nai la: %.2f", (sumtaitrong / count));
	}
}

//Câu 10
void find_KH(Slist sl)
{
	int count = 0;
	if (sl.Head == NULL) return;
	else {
		printf("\n\nCac kho hang co ten bat dau bang \"KH\" la: ");
		SNode* tmp = sl.Head;
		while (tmp != NULL)
		{
			if (strncmp("KH", tmp->data.tenkho, 2) == 0) {
				Xuattt(tmp->data);
				count++;
			}
			tmp = tmp->Next;
		}
		if (count == 0)
			printf("\nKhonh tim thay kho co ten bat dau la \"KH\"!");
		printf("\nCo %d kho hang!", count);
	}
}

void xoanut_lientruoc(Slist& sl, SNode* p)//Xóa nút trước nút p
{
	if (p == NULL || sl.Head == NULL || p == sl.Head) return;
	else
	{
		SNode* q = sl.Head;
		while (q->Next != p)
			q = q->Next;
		xoa_p(sl, q);
	}
}
void xoanut_liensau(Slist& sl, SNode* p) //Xóa nút sau nút p
{
	if (p == NULL || sl.Head == NULL || p == sl.Tail) return;
	else
	{
		xoa_p(sl, p->Next);
	}
}

void xoaall(Slist& sl) { //Xóa tất cả
	while (sl.Head != NULL) {
		xoa_dau(sl);
	}
}


//Duyệt danh sách
void duyet(Slist sl)
{
	if (isEmpty(sl) == true)
	{
		printf("\nDanh sach kho hang rong!");
	}
	else
	{
		printf("\n+===============================================================================================================================================+");
		printf("\n|                                                          THONG TIN KHO HANG                                                                   |");
		printf("\n+-----------------------------------------------------------------------------------------------------------------------------------------------+");
		printf("\n|  Ma kho hang\t|  Ten kho hang\t|   Dia diem\t|Tai trong hang\t|  Loai hang\t| Ngay nhap kho\t| Ngay xuat kho\t|    Tai trong hang nhap kho\t|");
		SNode* tmp = sl.Head;
		while (tmp != NULL)
		{
			Xuattt(tmp->data);
			tmp = tmp->Next;
		}
		printf("\n+===============================================================================================================================================+\n\n");
	}
}

void main() {
	Slist sl;
	initSlist(sl);
	int n, choice;
	khohang m[50];
	khohang x, a;
	const char* filename = "D:\\KhoHang.txt";
	do {
		printf("\n+===========================================MENU========================================+");
		printf("\n|0. De ket thuc chuong trinh.\t\t\t\t\t\t\t\t|");
		printf("\n|1. Tao danh sach bang cach nhap tu ban phim.\t\t\t\t\t\t|");
		printf("\n|2. Tao danh sach bang cach doc file.\t\t\t\t\t\t\t|");
		printf("\n|3. Them mot kho hang vao dau danh sach.\t\t\t\t\t\t|");
		printf("\n|4. Them mot kho hang vao cuoi danh sach.\t\t\t\t\t\t|");
		printf("\n|5. Them mot kho hang vao sau mot kho hang khac.\t\t\t\t\t|");
		printf("\n|6. Xoa kho hang o dau danh sach.\t\t\t\t\t\t\t|");
		printf("\n|7. Xoa kho hang o cuoi danh sach.\t\t\t\t\t\t\t|");
		printf("\n|8. Xoa kho hang tuy chon.\t\t\t\t\t\t\t\t|");
		printf("\n|9. Xoa kho hang phia truoc mot kho hang tuy chon.\t\t\t\t\t|");
		printf("\n|10. Xoa kho hang phia sau mot kho hang tuy chon.\t\t\t\t\t|");
		printf("\n|11. Xoa toan bo kho hang.\t\t\t\t\t\t\t\t|");
		printf("\n|12. Sap xep kho hang theo tai trong.\t\t\t\t\t\t\t|");
		printf("\n|13. Them mot kho hang nhung van dam bao trat tu sap xep o chuc nang \"9\".\t\t|");
		printf("\n|14. Tim cac kho hang duoc nhap vao thang va nam tuy chon.\t\t\t\t|");
		printf("\n|15. Tim cac kho hang con trong.\t\t\t\t\t\t\t|");
		printf("\n|16. Tim cac kho hang chua hang dong lanh.\t\t\t\t\t\t|");
		printf("\n|17. Tinh trung binh tai trong cua cac kho hang o Dong Nai.\t\t\t\t|");
		printf("\n|18. Tim cac kho hang co ten bat dau la \"KH\".\t\t\t\t\t\t|");
		printf("\n+=======================================================================================+");
		printf("\nNhap vao lua chon cua ban: ");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
		{
			Nhaptt(m, n);
			in(sl, m, n);
			duyet(sl);
			break;
		}
		case 2:
		{
			docfile(filename, m, n);
			in(sl, m, n);
			duyet(sl);
			break;
		}
		case 3:
		{
			Nhap(a);
			SNode* p = create_SNode(a);
			them_dau(sl, p);
			duyet(sl);
			break;
		}
		case 4: {
			Nhap(a);
			SNode* p1 = create_SNode(a);
			them_cuoi(sl, p1);
			duyet(sl);
			break;
		}
		case 5:
		{
			printf("\nNhap vao ma so cua kho hang phia truoc kho hang muon them vao: ");
			getchar();
			gets_s(x.makho);
			Nhap(a);
			SNode* p2 = create_SNode(a);
			thempsauq(sl, p2, timx(sl, x));
			duyet(sl);
			break;
		}
		case 6:
		{
			xoa_dau(sl);
			duyet(sl);
			break;
		}
		case 7:
		{
			xoa_cuoi(sl);
			duyet(sl);
			break;
		}
		case 8:
		{
			printf("\nNhap vao ma so cua kho hang muon xoa: ");
			getchar();
			gets_s(x.makho);
			xoa_p(sl, timx(sl, x));
			duyet(sl);
			break;
		}
		case 9:
		{
			printf("\nNhap vao ma so cua kho hang phia sau kho hang muon xoa: ");
			getchar();
			gets_s(x.makho);
			xoanut_lientruoc(sl, timx(sl, x));
			duyet(sl);
			break;
		}
		case 10:
		{
			printf("\nNhap vao ma so cua kho hang phia truoc kho hang muon xoa: ");
			getchar();
			gets_s(x.makho);
			xoanut_liensau(sl, timx(sl, x));
			duyet(sl);
			break;
		}
		case 11:
		{
			xoaall(sl);
			duyet(sl);
			break;
		}
		case 12:
		{
			sapxep(sl);
			duyet(sl);
			break;
		}
		case 13:
		{
			Nhap(a);
			SNode* p = create_SNode(a);
			them_x(sl, a);
			duyet(sl);
			break;
		}
		case 14:
		{
			find_date(sl, x);
			break;
		}
		case 15:
		{
			find_trong(sl);
			break;
		}
		case 16:
		{
			find_loai(sl);
			break;
		}
		case 17:
		{
			gpataitrong(sl);
			break;
		}
		case 18:
		{
			find_KH(sl);
			break;
		}
		default :
		{
			if (choice == 0)
			{
				printf("\nBan da ket thuc chuong trinh!");
			}
			else
			{
				printf("\nChuc nang vua nhap khong hop le. Vui long nhap lai!");
			}
			break;
		}
		}
	} while (choice != 0);
	_getch();

}