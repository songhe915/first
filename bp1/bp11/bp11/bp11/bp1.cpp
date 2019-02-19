#include "mex.h" 
#include  "math.h"


#define n_xy 500
#define c 1500
#define fs 100000000
#define m 1600
#define n 360


//out  �����ͼ�� 
//signal �����źţ������� 360*1600��
// m  �����źŵ�������1600�� 
//n   �����źŵ�������360�� 
//c ����
// fs      ����Ƶ��
//n_xy     �������
//pixpos_x ���ص��x����
//pixpos_y ���ص��y����
//senspos_x ̽������x����
//senspos_y ̽������y����

//c++���д洢����  �±��0��ʼ
void bp(double* out,double* signal,double* pixelpos_x,double* pixelpos_y,double* senspos_x,double* senspos_y)
{
  /*int rows=n_xy-1;
  int lines=n_xy-1;*/
  double ab;
  for(int k=0;k<n;k++)
  {
      for(int i=0;i<n_xy;i++)
	{
	    for(int j=0;j<n_xy;j++)
	      {
			  double pixel_inx=*(pixelpos_x+i);  
              double pixel_iny=*(pixelpos_y+j);
			  double senspos_idex=*(senspos_x+k);
			  double senspos_idey=*(senspos_y+k);
			  double s=sqrt((senspos_idex-pixel_inx)*(senspos_idex-pixel_inx)+(senspos_idey-pixel_iny)*(senspos_idey-pixel_iny));
			  int time=(int)((s/c)*fs);
			    if(time==0)
				    time=1;
				if(time>m)
				    time=m;
			 //*(out+j+i*n_xy)=(*(signal+k*m+time-1));
				//*(out+j+i*n_xy)=1;
				ab=signal[k*800];					
				*out=ab;
	        //*out=*(signal+k*m+time-1);
	      }
	 
	}
  
  }
}

// nlhs�����������Ŀ 
// plhs��ָ�����������ָ�� 
// nrhs�����������Ŀ
// prhs :ָ�����������ָ�� 
void mexFunction(int nlhs,mxArray *plhs[], int nrhs,const mxArray *prhs[])  
{  
	double* signal=mxGetPr(prhs[0]);      //��ò����źŵ�ָ��  ����
	double* pixelpos_x=mxGetPr(prhs[1]); //�����������x��ָ��  ����
	double* pixelpos_y=mxGetPr(prhs[2]); //�����������y��ָ��  ����
	double* senspos_x=mxGetPr(prhs[3]); //���λ������x��ָ��   ����
	double* senspos_y=mxGetPr(prhs[4]); //���λ������y��ָ��   ����

	plhs[0]=mxCreateDoubleMatrix(1,1,mxREAL);//�����������Ĵ�С  ���
	double* out=mxGetPr(plhs[0]);// ���������ݵ�ָ��   ���

	bp(out,signal,pixelpos_x,pixelpos_y,senspos_x,senspos_y);
}  