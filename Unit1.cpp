//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
//���������� ������������ ������� Matrix [8][8]
double det (double matrix[8][8])
{
     double ratio, det;
    int i, j, k, n=7;
    /* �������������� ������� � ������� ����������� */
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j>i){
                ratio = matrix[j][i]/matrix[i][i];
                for(k = 0; k < n; k++){
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }
    det = 1; //��������� ������������
    for(i = 0; i < n; i++)
        det *= matrix[i][i];
	return det;
}
//��������� ������� � ������� ����� ������ �����������
void get_matr(double matrix[8][8])
{
int k;//��������� �������� ������
//���������� ������� ��������� ��������� ��������������� ������
for (int i=0;i<8;i++)
	{
		k=0;
	for (int j=0;j<8;j++)
		if (matrix[i][j]==1)
			k++;
    matrix[i][i]=k;
     }
 //��������� ������� �� ��������� � ������� ���������
for (int i=0;i<8;i++)
	for (int j=0;j<8;j++)
		if (i!=j)
			matrix[i][j] = 0-matrix[i][j]; 

}

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  double matrix[8][8]={
	{0,1,0,0,1,0,1,0},
	{1,0,1,0,0,0,0,0},
	{0,1,0,1,0,0,1,0},
	{0,0,1,0,0,0,1,1},
	{1,0,0,0,0,1,0,0},
	{0,0,0,0,1,0,0,0},
	{1,0,1,1,0,0,0,1},
	{0,0,0,1,0,0,1,0}
	};
get_matr (matrix);
Edit1->Text =FloatToStr(det (matrix));
}
//---------------------------------------------------------------------------
