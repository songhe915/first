%重建
clear
clc
% mex bp1.cpp
load('E:\学习\pat\k-wave 模拟 2018312\2018331_0_360xueguan.mat')
%sigMat=sensor_output1';%待重建信号
sigMat=sensor_0_360; %待重建信号
%sigMat=sigMat(:,1:120);
%sigMat=sigMat(401:end,:);
c=1500; %声速
dt=1e-8;
fs=1/dt; %100MHz
image_width=8e-3; %Width (meters) 重建规模
n_xy=800;%网格个数 
%pixpos=zeros(2,500);
pixpos_x=linspace(-image_width/2,image_width/2,n_xy);%网格的横坐标
pixpos_y=linspace(-image_width/2,image_width/2,n_xy);%网格的纵坐标
% m=size(sigMat,2); %点数
% n=size(sigMat,1); %角度个数
%%
sigMat=single(sigMat);
t=((1:1:size(sigMat,1)))/fs; % time rate 
sigMat_devied = zeros(size(sigMat),'single');
sigMat_devied(1:(length(t)-1),:) = - single((sigMat(2:length(t),:)-sigMat(1:(length(t)-1),:))./(t(2)-t(1)));
%%
R=15e-3; % [m];%重建半径
therta=180:-1:-179;%角度间距   
senspos_x=R.*cos(therta*pi/180); %第一行 探测器y坐标
senspos_y=R.*sin(therta*pi/180); %第二行 探测器x坐标
sM=reshape(sigMat,1,[]);
%%
tic

image=bp1(sM,pixpos_x, pixpos_y,senspos_x,senspos_y);
toc

     


        




