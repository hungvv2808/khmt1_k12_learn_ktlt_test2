#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>

using namespace std;

void Input(double *&a, int &n){
        cout << "Nhap vao so phan tu trong day: "; cin >> n;
        a = new double [n];
        for(int i=0; i<n; i++) {
                cout << "a[" << i << "] = ";
                cin >> a[i];
        }
}

void Sort(double *a, int n){
        for(int i=0; i<n; i++) {
                for(int j=i+1; j<n; j++) {
                        if(a[j] < a[i]) {
                                double tg = a[i];
                                a[i] = a[j];
                                a[j] = tg;
                        }
                }
        }
}

double SumOfEvenNumber(double *a, int n){
        double sum = 0;
        for(int i=0; i<n; i++) {
                if(i%2==0) sum+=a[i];
        }
        return sum;
}

void OutputToScreen(double *a, int n){
        for(int i=0; i<n; i++) {
                cout << a[i] << " ";
        }
        cout << endl;
}

void OutputToFile(double *a, int n){
        ofstream OutputFile("assignment2.txt", ios::out);
        OutputFile << n << endl;
        for(int i=0; i<n; i++) {
                OutputFile << setiosflags(ios::fixed) << setprecision(2) << a[i] << " ";
        }
        OutputFile << endl;
        OutputFile << "end" << endl;
        OutputFile.close();
}

void TwoLargestValue(double *a, int n){
        cout << "Gia tri lon nhat trong mang vua nhap la: " << a[n-1] << endl;
        for(int i=n-1; i>=0; i--) {
                if(a[i] != a[n-1]) {
                        cout << "Gia tri lon thu hai trong mang vua nhap la: " << a[i] << endl;
                        break;
                }
        }
}

bool ThreePositiveNumberConsecutively(double *a, int n){
        for(int i=0; i<n; i++) {
                if(a[i]>0 && a[i+1]>0 && a[i+2]>0) return true;
        }
        return false;
}

void DeleteElement(double *&a, int &n){
        for(int i=0; i<n; i++) {
                if(a[i] > 5) {
                        for(int j=i; j<n; j++) a[j]=a[j+1];
                        n--;
                        i--;
                }
                a = (double*) realloc(a,n*sizeof(double));
        }
}

int main(){
        int n;  double *a;
        Input(a, n);
        Sort(a, n);
        cout << "Mang ban vua nhap sau khi sap xep la: ";
        OutputToScreen(a, n);
        cout << endl;
        cout << "Tong cac phan tu co chi so chan trong mang la: " << SumOfEvenNumber(a, n) << endl;
        cout << endl;
        OutputToFile(a, n);
        TwoLargestValue(a, n);
        cout << endl;
        if(ThreePositiveNumberConsecutively(a, n)) cout << "Mang nhap vao co chua ba so duong lien tiep." << endl;
        else cout << "Mang nhap vao khong chua ba so duong lien tiep." << endl;
        cout << endl;
        DeleteElement(a, n);
        cout << "Mang da nhap sau khi xoa cac phan tu lon hon 5 la: ";
        OutputToScreen(a, n);
        return 0;
}
