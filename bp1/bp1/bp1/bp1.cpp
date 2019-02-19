#include "mex.h" 
#include  "math.h"


#define n_xy 500
#define c 1500
#define fs 100000000
#define m 1600
#define n 360


//out  是输出图像 
//signal 输入信号（假设是 360*1600）
// m  输入信号的列数（1600） 
//n   输入信号的行数（360） 
//c 声速
// fs      采样频率
//n_xy     网格个数
//pixpos_x 像素点的x坐标
//pixpos_y 像素点的y坐标
//senspos_x 探测器的x坐标
//senspos_y 探测器的y坐标

//c++按行存储数组  下标从0开始
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

// nlhs：输出参数数目 
// plhs：指向输出参数的指针 
// nrhs：输入参数数目
// prhs :指向输入参数的指针 
void mexFunction(int nlhs,mxArray *plhs[], int nrhs,const mxArray *prhs[])  
{  
	double* signal=mxGetPr(prhs[0]);      //获得波形信号的指针  输入
	double* pixelpos_x=mxGetPr(prhs[1]); //获得像素坐标x的指针  输入
	double* pixelpos_y=mxGetPr(prhs[2]); //获得像素坐标y的指针  输入
	double* senspos_x=mxGetPr(prhs[3]); //获得位置坐标x的指针   输入
	double* senspos_y=mxGetPr(prhs[4]); //获得位置坐标y的指针   输入

	plhs[0]=mxCreateDoubleMatrix(1,1,mxREAL);//创建输出矩阵的大小  输出
	double* out=mxGetPr(plhs[0]);// 获得输出数据的指针   输出

	bp(out,signal,pixelpos_x,pixelpos_y,senspos_x,senspos_y);
}  