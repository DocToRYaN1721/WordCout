#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����һ������������ͳ���ļ��е��ַ���
int count_chars(FILE* fp) {
    int count = 0; //��ʼ��������
    char ch; //����һ���ַ����������ڴ洢��ȡ���ַ�
    while ((ch = fgetc(fp)) != EOF) { //ѭ����ȡ�ļ��е�ÿ���ַ���ֱ�������ļ�������
        count++; //ÿ��ȡһ���ַ�����������һ
    }
    return count; //���ؼ�������ֵ
}

//����һ������������ͳ���ļ��еĵ�����
int count_words(FILE* fp) {
    int count = 0; //��ʼ��������
    char ch; //����һ���ַ����������ڴ洢��ȡ���ַ�
    int flag = 0; //����һ����־�����������ж��Ƿ��������ʷָ������ո�򶺺ţ�
    while ((ch = fgetc(fp)) != EOF) { //ѭ����ȡ�ļ��е�ÿ���ַ���ֱ�������ļ�������
        if (ch == ' ' || ch == ',') { //�����ȡ���ո�򶺺�
            if (flag == 1) { //���֮ǰ�Ѿ������˵��ʵĿ�ʼ
                count++; //��������һ
                flag = 0; //���ñ�־����Ϊ0����ʾ�����˵��ʵĽ���
            }
        }
        else { //�����ȡ�������ַ�
            flag = 1; //���ñ�־����Ϊ1����ʾ�����˵��ʵĿ�ʼ
        }
    }
    if (flag == 1) { //����ļ�����ʱ����δ�����ĵ���
        count++; //��������һ
    }
    return count; //���ؼ�������ֵ
}

//������
int main(int argc, char* argv[]) {
    if (argc != 3) { //�����������������3�������������Ʋ������ļ�����
        printf("Usage: %s [-c|-w] [input_file_name]\n", argv[0]); //��ӡ�÷���ʾ��Ϣ
        exit(1); //�˳����򣬷��ش�����1
    }
    FILE* fp; //����һ���ļ�ָ����������ڴ��ļ�
    errno_t err = fopen_s(&fp, argv[2], "r");
    if (err != 0) {
        printf("Error: cannot open file %s\n", argv[2]);
        return -1;
    }
    //��ֻ��ģʽ��ָ�����ļ��������ļ�ָ�븳��fp
    if (fp == NULL) { //�����ʧ�ܣ��ļ������ڻ���Ȩ�ޣ�
        printf("Error: cannot open file %s\n", argv[2]); //��ӡ������Ϣ
        exit(2); //�˳����򣬷��ش�����2
    }
    if (strcmp(argv[1], "-c") == 0) { //������Ʋ���Ϊ-c��ͳ���ַ�����
        int chars = count_chars(fp); //����count_chars�����������ļ�ָ�룬�õ�����ֵ���ַ�����
        printf("Character count: %d\n", chars); //��ӡ�����Ϣ
    }
    else if (strcmp(argv[1], "-w") == 0) { //������Ʋ���Ϊ-w��ͳ�Ƶ�������
        int words = count_words(fp); //����count_words�����������ļ�ָ�룬�õ�����ֵ����������
        printf("Word count: %d\n", words); //��ӡ�����Ϣ
    }
    else { //������Ʋ����Ȳ���-cҲ����-w����Ч������
        printf("Error: invalid parameter %s\n", argv[1]); //��ӡ������Ϣ
        exit(3); //�˳����򣬷��ش�����3
    }
    fclose(fp); //�ر��ļ�
    return 0; //�����������򣬷���0
}