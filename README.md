# RetinalVessel-
This method aims to obtain the retinopathy from retinal vessel images

1、从生成式对抗网络分割眼底图像得到的血管图片A

2、使用 matlab程序细线化血管图片A ——>被白色围绕的血管图片B

3、二值化得到血管图片B的txt文件

4、使用C++程序changeTheImage将血管图片B外围的白色涂黑

5、使用C++程序FinalVesselSegmentation将血管图片B分解，得到相应的端点、边、交点txt数据

6、将端点、边、交点txt数据输入python k-core算法中，得到血管结构分级图以及所有核心分叉点

7、使用sort算法读…..Corenode.txt文件进行重新排序（注意要点击进入该文件删除最后一行）（建议后续实验者对此处进行改进，由于本程序对应点是通过横坐标排序得到的，所以遇到结构变化较大容易出现无法匹配的问题）

8、然后将两者数据输入ICP算法得到转换矩阵,并将初始图片通过python二值化

9、使用C++程序cucoloris进行剪影得到TXT文件

10、最后将txt文件通过python程序得到剪影图片

注：经过改良，建议大家学习我的路径格式，方便处理数据（只需要改数字 1  2  即可）

