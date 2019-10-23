#include<stdio.h>
#include<math.h>

int main(){
	double l, w, h, sita, ans;
	while(scanf("%lf %lf %lf %lf", &l, &w, &h, &sita) != EOF){
		ans = l * h;
		if((tan(sita*M_PI/180)*l) < h){
			ans = ans - (double)(0.5*l*l/cos(sita*M_PI/180)*sin(sita*M_PI/180));
		} else {
			ans = (double)(0.5*h*(tan((90-sita)*M_PI/180)*h));
		}
		printf("%.3lf mL\n",(ans*w));
	}
	return 0;
}
