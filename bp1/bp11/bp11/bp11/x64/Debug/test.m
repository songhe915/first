%�ؽ�
clear
clc
% mex bp1.cpp
load('E:\ѧϰ\pat\k-wave ģ�� 2018312\2018331_0_360xueguan.mat')
%sigMat=sensor_output1';%���ؽ��ź�
sigMat=sensor_0_360; %���ؽ��ź�
%sigMat=sigMat(:,1:120);
%sigMat=sigMat(401:end,:);
c=1500; %����
dt=1e-8;
fs=1/dt; %100MHz
image_width=8e-3; %Width (meters) �ؽ���ģ
n_xy=800;%������� 
%pixpos=zeros(2,500);
pixpos_x=linspace(-image_width/2,image_width/2,n_xy);%����ĺ�����
pixpos_y=linspace(-image_width/2,image_width/2,n_xy);%�����������
% m=size(sigMat,2); %����
% n=size(sigMat,1); %�Ƕȸ���
%%
sigMat=single(sigMat);
t=((1:1:size(sigMat,1)))/fs; % time rate 
sigMat_devied = zeros(size(sigMat),'single');
sigMat_devied(1:(length(t)-1),:) = - single((sigMat(2:length(t),:)-sigMat(1:(length(t)-1),:))./(t(2)-t(1)));
%%
R=15e-3; % [m];%�ؽ��뾶
therta=180:-1:-179;%�Ƕȼ��   
senspos_x=R.*cos(therta*pi/180); %��һ�� ̽����y����
senspos_y=R.*sin(therta*pi/180); %�ڶ��� ̽����x����
sM=reshape(sigMat,1,[]);
%%
tic

image=bp1(sM,pixpos_x, pixpos_y,senspos_x,senspos_y);
toc

     


        




