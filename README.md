# 小型学生成绩管理系统
题目：成绩管理系统
功能：一门课程的成绩管理系统包括学生成绩的录入、查询、列表等功能。
要求：
    利用结构数组存储所有学生信息，最多100个学生。编写学生成绩管理系统，其中学生的信息有学号、姓名（汉语拼音）和分数。
    
    完成下面函数：
    
    1、输入学生信息函数AddStd实现添加学生相关信息；
    
    2、按学号查询学生详细信息（包括成绩）QueryById;
    3、成绩列表函数ListAll按学号排序输出学生信息；
    4、输出平均分AvgScore；
    5、输出最高分MaxScore学生信息（需要注意的是最高分的学生可能不只一人）。

   利用while循环实现功能界面输出，根据用户选择调用对应的功能选项。所有学生成绩信息在退出系统时以文本文件保存到文件scores.txt（格式自定，可以是每个学生的信息和成绩占一行），在系统第一次运行时scores.txt被创建，每次系统运行时系统将从文件读入已保存的学生成绩信息。
测试内容：
20160801,caominghua,99.99
20170806,zhangsan,86.66
20120609,lisi,66.66
20110506,wangwu,96.36
20110603,zhuhd,69.00
20160809,mihub,45.00
20170806,liusiyuaan,99.00
20140566,minbufts,99.00
20785263,loomjyb,69.00
20170652,nbsydfysv,36.00
20560636,mihub,69.00
20562481,minuv,96.00
20160516,nullybsvs,79.00
截止日期 2018年6月26日
