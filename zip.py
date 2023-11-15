import os
import sys
import zipfile

#1.定义解压函数
def decompression(dirname):
    """
    :param dirname:文件所在的详细目录名,建议文件夹下面只有需要解压的文件，其他未做测试
    :return:
    """
    
    del_file="y"
    data = os.listdir(dirname)
    count=0
    for i in data:
        url = os.path.join(dirname, i)
        print(url)
        zip_file = zipfile.ZipFile(url)
        zip_list = zip_file.namelist()  # 得到压缩包里所有文件
        for f in zip_list:
            zip_file.extract(f, dirname)  # 循环解压文件到指定目录
            zip_file.close()  # 关闭文件，必须有，释放内存
            if del_file.upper()=="Y":
                os.remove(url)
            count+=1
        print("解压文件{}成功，删除{}成功".format(zip_list, zip_list))
    print("解压完成，共解压文件{}个".format(count))
for i in range(1,97):
    decompression("D:/anaconda program")
