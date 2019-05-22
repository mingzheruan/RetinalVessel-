clear;close all
BW1=imread('/Users/ruanmingzhe/Desktop/Data/data6/image2.gif');
%BW2 = Linearization(BW1)
B= [0 1 0
    1 1 1
    0 1 0]
%BW1open = bwmorph(BW1,'open');
%BW1close = imdilate(BW1open,B);%膨胀处理
%strel函数的功能是运用各种形状和大小构造结构元素

se1=strel('disk',0);%这里是创建一个半径为5的平坦型圆盘结构元素
A2=imerode(BW1,se1);%腐蚀
 BW2=bwmorph(A2,'thin',Inf);
 BW3close = imdilate(BW2,B);
BW4=bwmorph(BW3close,'thin',Inf);
figure,imshow(BW4)








