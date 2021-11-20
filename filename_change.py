import os

file_path = "../boj/"
file_names = os.listdir(file_path)

for i in file_names:
    v = i.split('_')
    if v[0] == "baekjun":
        print(v[1])
        src = os.path.join(file_path, i)
        dest = "boj_" + v[1]
        dest = os.path.join(file_path, dest);
        os.rename(src, dest)
