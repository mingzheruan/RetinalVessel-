clear;close all
BW1=imread('/Users/ruanmingzhe/Desktop/Data/data6/image2.gif');
%BW2 = Linearization(BW1)
B= [0 1 0
    1 1 1
    0 1 0]
%BW1open = bwmorph(BW1,'open');
%BW1close = imdilate(BW1open,B);%���ʹ���
%strel�����Ĺ��������ø�����״�ʹ�С����ṹԪ��

se1=strel('disk',0);%�����Ǵ���һ���뾶Ϊ5��ƽ̹��Բ�̽ṹԪ��
A2=imerode(BW1,se1);%��ʴ
 BW2=bwmorph(A2,'thin',Inf);
 BW3close = imdilate(BW2,B);
BW4=bwmorph(BW3close,'thin',Inf);
figure,imshow(BW4)








