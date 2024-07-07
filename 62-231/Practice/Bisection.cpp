#include<simplecpp>
#include<math.h>
    main_program{

    double xl=0,xr=2,xm,alpha=0.00001;

        while((xr-xl)>=alpha)
        { xm=(xl+xr)/2;
        if(((xl*xl-2>0) && (xm*xm-2>0)) ||
        ((xl*xl-2<0) && (xm*xm-2<0))) xl = xm;
        else xr=xm;
    cout <<"its value is " << xl << '\n';
}
  cout << '\n' << "Final value is; "<< xl ;
  cout << '\n' << "Final value is; " << xl ;
}
