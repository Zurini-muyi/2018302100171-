
#include <iostream>
#include <vector>
#include <algorithm> //导入swap函数
using namespace std;

void display(vector<int> chosenNum, int m){ //打印一组排列
    for (int i = 0; i < m; i++) {
        cout<<chosenNum[i]<<" ";
    }
    cout<<endl;
}

void permutation(vector<int> chosenNum, int m, int i){ //m个元素的全排列
    if (i>=m) {
        display(chosenNum, m);
    }
    else{
        for (int j=i; j<m; j++) {
            swap(chosenNum[i], chosenNum[j]);
            permutation(chosenNum, m, i+1);
            swap(chosenNum[i], chosenNum[j]);
        }
    }
}

void selectMNumbers(int n, int m, vector<int> indexVec, vector<int> numbers, int level){
    int begin,end;
    if (level==0)   //初始化从根节点开始遍历
        begin=0;
    else
        begin = indexVec[level-1] + 1;
    
    end = n-m+level;    //确定每层的尾指针
    for (int i = begin;i < end;i++)
    {
        indexVec[level] = i;    //将取到的元素的下标放在indexVec数组中,以递增方式排列
        if (level == m-1){   //已经取了m个元素
            vector<int> chosenNum;  //存储选出的数字
            for (int i = 0; i<m; i++) {
                chosenNum.push_back(numbers[indexVec[i]]);
            }
            permutation(chosenNum, m, 0);        //取出m个元素,再进行排列
        }
        else{
            selectMNumbers(n,m,indexVec,numbers,level+1); //继续取一个元素
        }
    }
}

int main(int argc, const char * argv[]) {
    int m = 2;
    vector<int> numbers = {1,2,3,4};
    vector<int> indexVec(m);    //记录所选取的m个数的下标
    selectMNumbers(5, 2, indexVec, numbers, 0);
    return 0;
}

