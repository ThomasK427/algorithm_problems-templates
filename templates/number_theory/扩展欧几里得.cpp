void extgcd(LL a, LL b, LL& d, LL& x, LL& y){
    if(b == 0){
        d = a;
        x = 1;
        y = 0;
    }
    else{
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

//通解，其中k为整数
LL x = x0 * c / d + k * b * c / d / d, y = y0 * c / d - k * a * c / d / d;
