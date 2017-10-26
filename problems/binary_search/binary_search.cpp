
//求右界
while(low < high){
    int mid = low + high + 1 >> 1;
    if(check(mid)){
        low = mid;
    }
    else{
        high = mid - 1;
    }
}
cout << low << endl;

//求左界
while(low < high){
    int mid = low + high >> 1;
    if(check(mid)){
        high = mid;
    }
    else{
        low = mid + 1;
    }
}
cout << high << endl;
