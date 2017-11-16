#include<stdio.h>
typedef struct p
{
	int x, y;
}P;
int Cross(P s, P e, P p)
{
	return (s.x-p.x)*(e.y-p.y)-(e.x-p.x)*(s.y-p.y);
}
int online(P s, P e, P p)
{
	if(((p.x-s.x)*(p.x-e.x)<=0)&&((p.y-s.y)*(p.y-e.y)<=0)&&(Cross(s, e, p)==0)) return 1;
	else return 0;
}
typedef struct R{
	int lx, ly, ux, uy;
}REC;
REC rec1, rec2;

int EXCLUDE(REC rec1, REC rec2){
	if(rec1.lx>rec2.ux)return 0;
	if(rec1.ux<rec2.lx)return 0;
	if(rec1.ly>rec2.uy)return 0;
	if(rec1.uy<rec2.ly)return 0;
	return 1;
}
int main(void)
{
	int line, i, cnt, pos, neg;
	P p0, p1, p2, p3, s, e;

	while(scanf("%d%d%d%d%d", &line, &p0.x, &p0.y, &p2.x, &p2.y))
	{
		if((line==0)&&(p0.x==0)&&(p0.y==0)&&(p2.x==0)&&(p2.y==0)) break;

		p1.x = p2.x;
		p1.y = p0.y;
		p3.x = p0.x;
		p3.y = p2.y;
		cnt = 0;
		rec1.lx=p0.x;
		rec1.ly=p0.y;
		rec1.ux=p2.x;
		rec1.uy=p2.y;
		for(i=0;i<line;i++)
		{
			scanf("%d %d %d %d", &s.x, &s.y, &e.x, &e.y);
			rec2.lx=(s.x<e.x)?s.x:e.x;
			rec2.ly=(s.y<e.y)?s.y:e.y;
			rec2.ux=(s.x>e.x)?s.x:e.x;
			rec2.uy=(s.y>e.y)?s.y:e.y;
			pos = neg = 0;
			if(EXCLUDE(rec1, rec2)){
				if((((p0.x<=s.x)&&(s.x<=p2.x))&&((p0.y<=s.y)&&(s.y<=p2.y)))||(((p0.x<=e.x)&&(e.x<=p2.x))&&((p0.y<=e.y)&&(e.y<=p2.y))))
					cnt++;
				else if((( (p0.x<=s.x) && (s.x<=p2.x) ) && ( (p0.x<=e.x) && (e.x<=p2.x) )&&(s.y<=p0.y)&&(e.x>=p2.y))||
						((s.x<=p0.x)&&(e.x>=p2.x)&&((p0.y<=s.y)&&(s.y<=p2.y))&&((p0.y<=e.y)&&(e.y<=p2.y))))
					cnt++;
				else if(online(s, e, p0)||online(s, e, p1)||online(s, e, p2)||online(s, e, p3))
					cnt++;
				else{
					if(Cross(s, e, p0)>=0) pos++;
					else neg++;

					if(Cross(s, e, p1)>=0) pos++;
					else neg++;

					if(Cross(s, e, p2)>=0) pos++;
					else neg++;

					if(Cross(s, e, p3)>=0) pos++;
					else neg++;

					if((pos==3)||(neg==3)||(pos==2))
						cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
