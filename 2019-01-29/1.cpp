#include <iostream>
using namespace std;
class double_vector{
int size;
int cap;
double* data;
bool is_sort;
public:
    double_vector(){
    size=1;
    cap=1;
    data=0;
    is_sort=false;
    }
    double_vector(int n){
    this->size=n;
    this->cap=n;
    this->is_sort=false;
    this->data = new double[n];
    for(int i=0;i<n;i++){
        *(data+i)=0;
    }
    }
    double_vector(double_vector& ar){
    this->size=ar.size;
    this->is_sort=ar.is_sort;
    this->data=new double[ar.size];
    for(int i=0;i<ar.size;i++){
        this->data[i]=ar.data[i];
    }
    }
    double_vector(const double_vector& ar){
    this->cap=ar.cap;
    this->size=ar.size;
    this->data=ar.data;
    }
    double operator[](int x){
    while(x>=this->size)x-=this->size;
    return this->data[x];
    }
    const double_vector& operator=(const double_vector& ar){
    this->size=ar.size;
    this->cap=ar.cap;
    this->data=new double[ar.size];
    for(int i=0;i<ar.size;i++){
        this->data[i]=ar.data[i];
    }
    }
    void in(int i,int x){
    *(data+i)=x;
    }
    void push_back(double x){
    if (size>=cap){
    cap*=2;
    }
    double* tmp=new double[cap];
    for(int i=0;i<size;i++){
        tmp[i]=data[i];
    }
        delete [] data;
        data=tmp;
        data[size]=x;
        size++;
    }
    void push_front(double x){
    if (size>=cap){
    cap*=2;
    }
    double* tmp=new double[cap];
    for(int i=1;i<size;i++){
        tmp[i]=data[i-1];
    }
        delete [] data;
        data=tmp;
        data[0]=x;
        size++;
    }
    double pop_back(){
    double x=data[size-1];
    double* tmp=new double[cap];
    for(int i=0;i<size-1;i++){
        tmp[i]=data[i];
    }
    delete [] data;
    data=tmp;
    size--;
    return x;
    }
    double pop_front(){
    double x=data[0];
    double* tmp = new double[cap];
    for(int i=0;i<size-1;i++){
        tmp[i]=data[i+1];
    }
    delete [] data;
    data=tmp;
    size--;
    return x;
    }
    void insert(double x,int pos){
    if (size>=cap){
    cap*=2;
    }
    double*  tmp=new double[cap];
    for(int i=0;i<pos;i++){
        tmp[i]=data[i];
    }
    tmp[pos]=x;
    for(int i=pos+1;i<size;i++){
        tmp[i]=data[i-1];
    }
    delete [] data;
    data=tmp;
    size++;
    }
    void erase(int pos){
    double* tmp=new double[cap];
    for(int i=0;i<size;i++){
        if(i<pos)tmp[i]=data[i];
        else if(i>pos)tmp[i-1]=data[i];
    }
    delete [] data;
    data = tmp;
    size--;
    }
    void erasel(int a,int b){
    double* tmp=new double[cap];
    for(int i=0;i<a;i++){
        tmp[i]=data[i];
    }
    for(int i=b+1;i<size;i++){
        tmp[i-b+a]=data[i];
    }
    delete []data;
    data=tmp;
    size-=(b-a);
    }
    double_vector& operator+(double_vector& ar){
    this->cap+=ar.getcap();
    double* tmp = new double[this->cap];
    this->is_sort=false;
    for(int i=0;i<this->size;i++){
        tmp[i]=this->data[i];
    }
    for(int i=0;i<ar.getsize();i++){
        tmp[i+this->size]=ar[i];
    }
    delete [] data;
    data=tmp;
    this->size+=ar.getsize();
    }
    double find(double key){
    int search=-1;
    for(int i=0;i<this->size;i++){
        if(data[i]==key)search=i;
    }
    return search;
    }
    int getsize(){
    return this->size;
    }
    int getcap(){
    return this->cap;
    }
    void qSort(int left,int right) {
    this->is_sort=true;
    int i = left, j = right;
    int tmp;
    int pivot = data[(left + right) / 2];
    while (i <= j) {
        while (data[i] < pivot)
        i++;
        while (data[j] > pivot)
        j--;
        if (i <= j) {
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            i++;
            j--;
        }
    };
    if (left < j)
    qSort(left, j);
    if (i < right)
    qSort(i, right);
}
int binfind(double key){
if(this->is_sort==true)
    {
int left = 0;
int right = 19;
int search = -1;
while (left <= right)
  {
   int mid = (left + right) / 2;
    if (key == data[mid]) {
      search = mid;
      break;
    }
    if (key < data[mid])
      right = mid - 1;
    else
      left = mid + 1;
  }
  return search;
  }
  else return -1;
}
    ~double_vector(){
    delete [] data;
    }
};
