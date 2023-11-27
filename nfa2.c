
#include<stdio.h>
#define SIZE 40
#define MAX 20

//=========================================================
struct nfa_state
{
	int a, b,c,d,e,f,g,h,i,j,k,l,m,n,o,v,u,p,q,r,s,t,w,x,y,z;
	int eps1 ,eps2 ,eps3, eps4 ,eps5 ,eps6 ,eps7 ,eps8, eps9 ,eps10 ,eps11 ,eps12 ,eps13, eps14 ,eps15 ,eps16 ,eps17 ,eps18, eps19 ,eps20 ,eps21 ,eps22 ,eps23, eps24 ,eps25 ,eps26 ;

}NFA[20];

struct dfa_state
{
	int state[20],a[20],b[20],c[20],d[20],e[20],f[20],g[20],h[20],i[20],j[20],k[20],l[20],m[20],n[20],o[20],p[20],q[20],r[20],s[20],t[20],u[20],v[20],w[20],x[20],y[20],z[20];
}DFA[60];
int size_of_accept=0;
int cur, initial_state, final_state,abc=0,cba=0,xyz=0,xy1=0,xy2=0,xy3=0,xy4=0,xy5=0,xy6=0,xy7=0,xy8=0,xy9=0,x10=0,
     x11=0,x12=0,x13=0,x14=0,x15=0,x16=0,x17=0,x18=0,x19=0,x20=0,x21=0,x22=0,x23=0,x24=0,x,sum=0,count=0;
int dfa_accept[20];

int graph[25];

int stack[MAX];
int top;
int arr[20][27];

char stack1[SIZE];
int top1=-1;

int stack[MAX];
int top;
int arr[20][27];
//===========================================================================
void push1(char data)
{
    if(top1==SIZE-1)
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        top1   =top1+1;
        stack1[top1]=data;
        printf("Pushed element is %c\n",data);
    }
}

char pop1()
{
    char ch1;
    if(top1<0)
    {
        printf("stack is empty\n");
        return "h";
    }
    else
    {
        ch1=stack1[top1];
        printf("poped element is%c\n",ch1);
        top1=top1-1;
        return(ch1);
    }
}

int check_pre(char a ,char b)
{
    //operators are arranged in the array based
    //on their priority. from low to high
    char op[]={'-','+','%','.','*','(',')'};
    int i,c1=0,c2=0;
    for(i=0;i<7;i++)
    {
        if(a==op[i])
            c1=i+1;
        else if(b==op[i])
            c2=i+1;
    }
    if(c1>c2)
        return(1);
    else if(c1<c2)
        return(-1);
    else
        return(0);
}//=========================================================


//=========================================================
void push(int val)
{
	stack[++top]=val;
}

int pop()
{
	return stack[top--];
}
//=========================================================
int priority(char op)
{
	switch(op)
	{
	case '+':	return 1;
	case '.':	return 2;
	case '*':  	return 3;
	}
	return 0;
}
//=========================================================
void init_nfa_table()
{
	int i;
	for(i=0; i<20; i++)
	{NFA[i].u=-1;
		NFA[i].a = NFA[i].b =NFA[i].c=NFA[i].d = NFA[i].e =NFA[i].f=NFA[i].g = NFA[i].h =NFA[i].i=-1;
		NFA[i].j = NFA[i].k =NFA[i].l=NFA[i].m = NFA[i].n =NFA[i].o=NFA[i].p = NFA[i].q =NFA[i].r=-1;
NFA[i].s = NFA[i].t =NFA[i].v = NFA[i].w =NFA[i].x=NFA[i].y = NFA[i].z =-1;
		NFA[i].eps1 = NFA[i].eps2 =NFA[i].eps3=NFA[i].eps4 = NFA[i].eps5 =NFA[i].eps6=NFA[i].eps7 = NFA[i].eps8 =NFA[i].eps9=NFA[i].eps10 = NFA[i].eps11=NFA[i].eps12=NFA[i].eps13 = NFA[i].eps14 =NFA[i].eps15= -1;
		NFA[i].eps16 = NFA[i].eps17 =NFA[i].eps18=NFA[i].eps19 = NFA[i].eps20 =NFA[i].eps21=NFA[i].eps22 = NFA[i].eps23 =NFA[i].eps24=NFA[i].eps25 = NFA[i].eps26=-1;
	}
}
//=========================================================
void symbol(char c)
{
    printf("\n%d\n",cur);
	if(c=='a')
		NFA[cur].a = cur+1;
	printf("NFA[cur].a = cur+1;");
	printf("\t%d\t",NFA[cur].a);
    printf("\t%d\t",NFA[cur].b);
    printf("\t%d\t",NFA[cur].eps1);
    printf("\t%d\t",NFA[cur].eps2);
    printf("\n");

    if(c=='b')
        NFA[cur].b=cur+1;
	if(c=='c')
		NFA[cur].c = cur+1;
if(c=='d')
		NFA[cur].d = cur+1;
if(c=='e')
		NFA[cur].e = cur+1;
if(c=='f')
		NFA[cur].f = cur+1;
if(c=='g')
		NFA[cur].g = cur+1;
if(c=='h')
		NFA[cur].h = cur+1;
if(c=='i')
		NFA[cur].i = cur+1;
if(c=='j')
		NFA[cur].j = cur+1;
if(c=='k')
		NFA[cur].k = cur+1;
if(c=='l')
		NFA[cur].l = cur+1;
if(c=='m')
		NFA[cur].m = cur+1;
if(c=='n')
		NFA[cur].n = cur+1;
if(c=='o')
		NFA[cur].o = cur+1;
if(c=='p')
		NFA[cur].p = cur+1;
if(c=='q')
		NFA[cur].q = cur+1;
if(c=='r')
		NFA[cur].r = cur+1;
if(c=='s')
		NFA[cur].s = cur+1;
if(c=='t')
		NFA[cur].t = cur+1;
if(c=='u')
		NFA[cur].u = cur+1;
if(c=='v')
		NFA[cur].v = cur+1;
if(c=='w')
		NFA[cur].w = cur+1;
if(c=='x')
		NFA[cur].x = cur+1;
if(c=='y')
		NFA[cur].y = cur+1;
if(c=='z')
		NFA[cur].z = cur+1;

	push(cur);
	push(cur+1);

	cur += 2;
	int j=0;
	for(;j<6;j++)
    {
    printf("\t%d ",NFA[j].a);

    printf("\t%d ",NFA[j].b);
    printf("\t%d ",NFA[j].c);
    printf("\t%d ",NFA[j].d);



    printf("\t%d ",NFA[j].eps1);
    printf("\t%d",NFA[j].eps2);
    printf("\n");
    }

}
//=========================================================
void concat()
{
	int first1, first2, last1, last2;

	last2 = pop();
	first2 = pop();
	last1 = pop();
	first1 = pop();

	NFA[last1].eps1 = first2;

	push(first1);
	push(last2);
}
//=========================================================
void parallel()
{
	int first1, first2, last1, last2;

	last2 = pop();
	first2 = pop();
	last1 = pop();
	first1 = pop();

printf("%d %d %d %d\n",last2,first2,last1,first1);
	NFA[cur].eps1 = first1;
	NFA[cur].eps2 = first2;
	NFA[last1].eps1 = cur+1;
	NFA[last2].eps2 = cur+1;

	push(cur);
	push(cur+1);
	cur += 2;
}
//=========================================================
void closure()
{
	int first,last;

	last = pop();
	first = pop();

	NFA[cur].eps1 = first;
	NFA[cur].eps2 = cur+1;
	NFA[last].eps1 = first;
	NFA[last].eps2 = cur+1;

	push(cur);
	push(cur+1);

	cur += 2;
}
//=========================================================
void construct_nfa(char *postfix)
{
	int i=0;

	top=-1;

	for(i=0; postfix[i]!='\0'; i++)
	{
		switch(postfix[i])
		{
		case 'a':
        case 'c':
        case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z':

		case 'b':	symbol(postfix[i]);
					break;
		case '.':	concat();
					break;
		case '+': 	parallel();
					break;
		case '*':	closure();
		}
	}
	final_state = pop();
	initial_state = pop();
}
//=========================================================
void disp_NFA()
{
	int i;
	printf("\nstate\ta\tb\tc\td\te\tf\tg\th\ti\tj\tk\tl\tm\tn\to\tp\tq\tr\ts\tt\tu\tv\tw\tx\ty\tz\t�");
	for(i=0;i<cur;i++)
	{
		if(i==initial_state)
			printf("\n->%d",i);
		else
		 if(i==final_state)
			printf("\n* %d",i);
		else
			printf("\n  %d",i);

		if(NFA[i].a==-1)
			printf("\t-");
		else
			printf("\t{%d}",NFA[i].a);

		if(NFA[i].b==-1)
			printf("\t-");
		else
			printf("\t{%d},%d",NFA[i].b,i);

        if(NFA[i].c==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].c);
       if(NFA[i].d==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].d);
if(NFA[i].e==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].e);
if(NFA[i].f==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].f);
if(NFA[i].g==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].g);
if(NFA[i].h==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].h);
if(NFA[i].i==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].i);
if(NFA[i].j==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].j);
if(NFA[i].k==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].k);
if(NFA[i].l==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].l);
if(NFA[i].m==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].m);
if(NFA[i].n==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].n);
if(NFA[i].o==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].o);
if(NFA[i].p==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].p);
if(NFA[i].q==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].q);
if(NFA[i].r==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].r);
if(NFA[i].s==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].s);
if(NFA[i].t==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].t);
if(NFA[i].u==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].u);
if(NFA[i].v==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].v);
if(NFA[i].w==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].w);
if(NFA[i].x==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].x);
if(NFA[i].y==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].y);
if(NFA[i].z==-1)
            printf("\t-");
        else
        printf("\t{%d}",NFA[i].z);
		if(NFA[i].eps1!=-1)    //problem is here eps2 is checking after eps2
		{
			printf("\t{%d",NFA[i].eps1);
			if(NFA[i].eps2!=-1)
			{
				printf(",%d",NFA[i].eps2);
			}
			printf("}");
		}
		else
			printf("\t-");
	}
}
//=========================================================
void init_dfa_table()
{
	int i,j;
	for(i=0;i<60;i++)
	{
		for(j=0;j<60;j++)
		{
			DFA[i].state[j]=-1;
			DFA[i].a[j]=-1;
			DFA[i].b[j]=-1;
			DFA[i].c[j]=-1;
			DFA[i].d[j]=-1;
		    DFA[i].e[j]=-1;
			DFA[i].f[j]=-1;
			DFA[i].g[j]=-1;
			DFA[i].h[j]=-1;
		    DFA[i].i[j]=-1;
			DFA[i].j[j]=-1;
			DFA[i].k[j]=-1;
			DFA[i].l[j]=-1;
		    DFA[i].m[j]=-1;
			DFA[i].n[j]=-1;
			DFA[i].o[j]=-1;
			DFA[i].p[j]=-1;
		    DFA[i].q[j]=-1;
			DFA[i].r[j]=-1;
			DFA[i].s[j]=-1;
			DFA[i].t[j]=-1;
	     	DFA[i].u[j]=-1;
			DFA[i].v[j]=-1;
			DFA[i].w[j]=-1;
			DFA[i].x[j]=-1;
		    DFA[i].y[j]=-1;
			DFA[i].z[j]=-1;

		}
	}
}
//=========================================================
void print_state(int t[],int x,int v)
{
	int i=0,final=0;
	printf("[");
	for(i=0;t[i]!=-1;i++)
		printf("%d,",t[i]);
	printf("\b]");
	if(x==24)
        { for(i=0;t[i]!=-1;i++)
        	{
        	if(t[i]==v)
        		final++;
		 sum=sum*10+t[i];
		}
	     arr[abc][0]=sum;
	     abc++;
	     if(final)
	     {
	     	dfa_accept[count]=sum;
	     	count++;
	     }
	 }
	 if(x==25)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[cba][1]=sum;
	 	cba++;
	 }
	 if(x==26)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[xyz][2]=sum;
	 	xyz++;
	 }
	 if(x==27)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[xy1][3]=sum;
	 	xy1++;
	 }
	 if(x==28)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[xy2][4]=sum;
	 	xy2++;
	 }
	 if(x==29)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[xy3][5]=sum;
	 	xy3++;
	 }
	 if(x==30)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[xy4][6]=sum;
	 	xy4++;
	 }
	 if(x==31)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[xy5][7]=sum;
	 	xy5++;
	 }
	 if(x==32)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[xy6][8]=sum;
	 	xy6++;
	 }
	 if(x==33)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[xy7][9]=sum;
	 	xy7++;
	 }
	 if(x==34)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[xy8][10]=sum;
	 	xy8++;
	 }
	 if(x==35)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[xy9][11]=sum;
	 	xy9++;
	 }
	 if(x==36)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x10][12]=sum;
	 	x10++;
	 }
	 if(x==37)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x11][13]=sum;
	 	x11++;
	 }
	 if(x==38)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x12][14]=sum;
	 	x12++;
	 }
	 if(x==39)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x13][15]=sum;
	 	x13++;
	 }
	 if(x==40)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x14][16]=sum;
	 	x14++;
	 }
	 if(x==41)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x15][17]=sum;
	 	x15++;
	 }
	 if(x==42)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x16][18]=sum;
	 	x16++;
	 }
	 if(x==43)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x17][19]=sum;
	 	x17++;
	 }
	 if(x==44)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x18][20]=sum;
	 	x18++;
	 }
	 if(x==45)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x19][21]=sum;
	 	x19++;
	 }
	 if(x==46)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x20][22]=sum;
	 	x20++;
	 }
	 if(x==47)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x21][23]=sum;
	 	x21++;
	 }
	 if(x==48)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x22][24]=sum;
	 	x22++;
	 }
	 if(x==49)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x23][25]=sum;
	 	x23++;
	 }
	 if(x==50)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[x24][26]=sum;
	 	x24++;
	 }
	 sum=0;
}
//=========================================================

void print_state_array(int t[],int x)
{
	int i=0;
	if(x==24)
        { for(i=0;t[i]!=-1;i++)
		 sum=sum*10+t[i];
	     arr[abc][0]=sum;
	     abc++;
	 }
	 if(x==25)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[cba][1]=sum;
	 	cba++;
	 }
	 if(x==26)
	 {
	 	for(i=0;t[i]!=-1;i++)
	 		sum=sum*10+t[i];
	 	arr[xyz][2]=sum;
	 	xyz++;
	 }
	 sum=0;

}
//=========================================================
int isPresent(int T[], int v)
{
	int i;
	for(i=0;T[i]!=-1;i++)
		if(T[i]==v)
			return 1;
	return 0;
}
//=========================================================
void disp_DFA(int n)
{
	int i;
	printf("\nstate\t\ta\t\t\tb\t\tc\t\td\t\te\t\tf\t\tg\t\th\t\ti\t\tj\t\tk\t\tl\t\tm\t\tn\t\to\t\tp\t\tq\t\tr\t\ts\t\tt\t\tu\t\tv\t\tx\t\ty\t\tz");
	for(i=0;i<=n;i++)
	{
		printf("\n");
		if(i==0)
			printf("->");

		if(isPresent(DFA[i].state,final_state))
			printf("*");

			print_state(DFA[i].state,24,final_state);
			printf("\t\t");

		if(DFA[i].a[0]!=-1)
			print_state(DFA[i].a,25,final_state);
		else
		{
			arr[cba][1]=-1;
			cba++;
			printf("-");
		}
		printf("\t\t");
		if(DFA[i].b[0]!=-1)
			print_state(DFA[i].b,26,final_state);
		else
		{
			printf("-");
			arr[xyz][2]=-1;
			xyz++;
		}printf("\t\t");
		if(DFA[i].c[0]!=-1)
			print_state(DFA[i].c,27,final_state);
		else
		{
			printf("-");
			arr[xy1][3]=-1;
			xy1++;
		}printf("\t\t");
		if(DFA[i].d[0]!=-1)
			print_state(DFA[i].d,28,final_state);
		else
		{
			printf("-");
			arr[xy2][4]=-1;
			xy2++;
		}printf("\t\t");
		if(DFA[i].e[0]!=-1)
			print_state(DFA[i].e,29,final_state);
		else
		{
			printf("-");
			arr[xy3][5]=-1;
			xy3++;
		}printf("\t\t");
		if(DFA[i].f[0]!=-1)
			print_state(DFA[i].f,30,final_state);
		else
		{
			printf("-");
			arr[xy4][6]=-1;
			xy4++;
		}printf("\t\t");
		if(DFA[i].g[0]!=-1)
			print_state(DFA[i].g,31,final_state);
		else
		{
			printf("-");
			arr[xy5][7]=-1;
			xy5++;
		}printf("\t\t");
		if(DFA[i].h[0]!=-1)
			print_state(DFA[i].h,32,final_state);
		else
		{
			printf("-");
			arr[xy6][8]=-1;
			xy6++;
		}printf("\t\t");
		if(DFA[i].i[0]!=-1)
			print_state(DFA[i].i,33,final_state);
		else
		{
			printf("-");
			arr[xy7][9]=-1;
			xy7++;
		}printf("\t\t");
		if(DFA[i].j[0]!=-1)
			print_state(DFA[i].j,34,final_state);
		else
		{
			printf("-");
			arr[xy8][10]=-1;
			xy8++;
		}printf("\t\t");
		if(DFA[i].k[0]!=-1)
			print_state(DFA[i].k,35,final_state);
		else
		{
			printf("-");
			arr[xy9][11]=-1;
			xy9++;
		}printf("\t\t");
		if(DFA[i].l[0]!=-1)
			print_state(DFA[i].l,36,final_state);
		else
		{
			printf("-");
			arr[x10][12]=-1;
			x10++;
		}printf("\t\t");
		if(DFA[i].m[0]!=-1)
			print_state(DFA[i].m,37,final_state);
		else
		{
			printf("-");
			arr[x11][13]=-1;
			x11++;
		}printf("\t\t");
		if(DFA[i].n[0]!=-1)
			print_state(DFA[i].n,38,final_state);
		else
		{
			printf("-");
			arr[x12][14]=-1;
			x12++;
		}printf("\t\t");
		if(DFA[i].o[0]!=-1)
			print_state(DFA[i].o,39,final_state);
		else
		{
			printf("-");
			arr[x13][15]=-1;
			x13++;
		}printf("\t\t");
		if(DFA[i].p[0]!=-1)
			print_state(DFA[i].p,40,final_state);
		else
		{
			printf("-");
			arr[x14][16]=-1;
			x14++;
		}printf("\t\t");
		if(DFA[i].q[0]!=-1)
			print_state(DFA[i].q,41,final_state);
		else
		{
			printf("-");
			arr[x15][17]=-1;
			x15++;
		}printf("\t\t");
		if(DFA[i].r[0]!=-1)
			print_state(DFA[i].r,42,final_state);
		else
		{
			printf("-");
			arr[x16][18]=-1;
			x16++;
		}printf("\t\t");
		if(DFA[i].s[0]!=-1)
			print_state(DFA[i].s,43,final_state);
		else
		{
			printf("-");
			arr[x17][19]=-1;
			x17++;
		}printf("\t\t");
		if(DFA[i].t[0]!=-1)
			print_state(DFA[i].t,44,final_state);
		else
		{
			printf("-");
			arr[x18][20]=-1;
			x18++;
		}printf("\t\t");
		if(DFA[i].u[0]!=-1)
			print_state(DFA[i].u,45,final_state);
		else
		{
			printf("-");
			arr[x19][21]=-1;
			x19++;
		}printf("\t\t");
		if(DFA[i].v[0]!=-1)
			print_state(DFA[i].v,46,final_state);
		else
		{
			printf("-");
			arr[x20][22]=-1;
			x20++;
		}printf("\t\t");
		if(DFA[i].w[0]!=-1)
			print_state(DFA[i].w,47,final_state);
		else
		{
			printf("-");
			arr[x21][23]=-1;
			x21++;
		}printf("\t\t");
		if(DFA[i].x[0]!=-1)
			print_state(DFA[i].x,48,final_state);
		else
		{
			printf("-");
			arr[x22][24]=-1;
			x22++;
		}printf("\t\t");
		if(DFA[i].y[0]!=-1)
			print_state(DFA[i].y,49,final_state);
		else
		{
			printf("-");
			arr[x23][25]=-1;
			x23++;
		}
		printf("\t\t");
		if(DFA[i].z[0]!=-1)
			print_state(DFA[i].z,50,final_state);
		else
		{
			printf("-");
			arr[x24][26]=-1;
			x24++;
		}

	}
}
//=========================================================
void epsilon_closure(int T[], int t[])
{
	int i,v;
	top=-1;

	for(i=0;t[i]!=-1;i++)
		push(t[i]);

	i=0;

	while(top!=-1)
	{
		v = pop();

		if(isPresent(T,v)==0)
		{
			T[i++]=v;
		}

		if(NFA[v].eps1!=-1)
		{
			push(NFA[v].eps1);
		}

		if(NFA[v].eps2!=-1)
		{
			push(NFA[v].eps2);
		}
	}
}
//=========================================================
void init_t(int t[])
{
	int i;
	for(i=0;i<20;i++)
		t[i]=-1;
}
//=========================================================
int search(int n,int t2[])
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;t2[j]!=-1;j++)
			if(isPresent(DFA[i].state,t2[j])==0)
				break;
		if(t2[j]==-1)
			return 1;
	}
	return 0;
}
//=========================================================
void copy(int t1[], int t2[])
{
	int i;
	for(i=0;t2[i]!=-1;i++)
		t1[i]=t2[i];
}
//=========================================================
fsm()
{
	int i=0;
	FILE *fp;
	fp=fopen("fsm.gv","w");
	fprintf(fp,"digraph finite_state_machine {\nrankdir=LR\nsize=\"8,5\"\nnode [shape=doublecircle]\n");


	while(dfa_accept[i]!=-1)
	{
		fprintf(fp,"%d\n",dfa_accept[i]);
		i++;
	}

	fprintf(fp, "node [shape=point] qi\n");

	fprintf(fp, "node [shape=circle]\n");

    fprintf(fp,"qi -> %d \n",arr[0][0]);

	for(i=0;i<10;i++)
	{

			if(arr[i][0]==-1)
				break;


         if(graph[0])
		     fprintf(fp,"%d -> %d [label=\"a\"]\n",arr[i][0],arr[i][1]);
	     if(graph[1])
		    fprintf(fp,"%d -> %d [label=\"b\"]\n",arr[i][0],arr[i][2]);
	    if(graph[2])
		    fprintf(fp,"%d -> %d [label=\"c\"]\n",arr[i][0],arr[i][3]);
	    if(graph[3])
		    fprintf(fp,"%d -> %d [label=\"d\"]\n",arr[i][0],arr[i][4]);
		if(graph[4])
			fprintf(fp,"%d -> %d [label=\"e\"]\n",arr[i][0],arr[i][5]);
		if(graph[5])
			fprintf(fp,"%d -> %d [label=\"f\"]\n",arr[i][0],arr[i][6]);
		if(graph[6])
			fprintf(fp,"%d -> %d [label=\"g\"]\n",arr[i][0],arr[i][7]);
		if(graph[7])
			fprintf(fp,"%d -> %d [label=\"h\"]\n",arr[i][0],arr[i][8]);
		if(graph[8])
			fprintf(fp,"%d -> %d [label=\"i\"]\n",arr[i][0],arr[i][9]);
		if(graph[9])
			fprintf(fp,"%d -> %d [label=\"j\"]\n",arr[i][0],arr[i][10]);
		if(graph[10])
			fprintf(fp,"%d -> %d [label=\"k\"]\n",arr[i][0],arr[i][11]);
		if(graph[11])
			fprintf(fp,"%d -> %d [label=\"l\"]\n",arr[i][0],arr[i][12]);
		if(graph[12])
			fprintf(fp,"%d -> %d [label=\"m\"]\n",arr[i][0],arr[i][13]);
		if(graph[13])
			fprintf(fp,"%d -> %d [label=\"n\"]\n",arr[i][0],arr[i][14]);
		if(graph[14])
			fprintf(fp,"%d -> %d [label=\"o\"]\n",arr[i][0],arr[i][15]);
		if(graph[15])
			fprintf(fp,"%d -> %d [label=\"p\"]\n",arr[i][0],arr[i][16]);
		if(graph[16])
			fprintf(fp,"%d -> %d [label=\"q\"]\n",arr[i][0],arr[i][17]);
		if(graph[17])
			fprintf(fp,"%d -> %d [label=\"r\"]\n",arr[i][0],arr[i][18]);
		if(graph[18])
			fprintf(fp,"%d -> %d [label=\"s\"]\n",arr[i][0],arr[i][19]);
		if(graph[19])
			fprintf(fp,"%d -> %d [label=\"t\"]\n",arr[i][0],arr[i][20]);
		if(graph[20])
			fprintf(fp,"%d -> %d [label=\"u\"]\n",arr[i][0],arr[i][21]);
		if(graph[21])
			fprintf(fp,"%d -> %d [label=\"v\"]\n",arr[i][0],arr[i][22]);
		if(graph[22])
			fprintf(fp,"%d -> %d [label=\"w\"]\n",arr[i][0],arr[i][23]);
		if(graph[23])
			fprintf(fp,"%d -> %d [label=\"x\"]\n",arr[i][0],arr[i][24]);
		if(graph[24])
			fprintf(fp,"%d -> %d [label=\"y\"]\n",arr[i][0],arr[i][25]);
		if(0)
			fprintf(fp,"%d -> %d [label=\"z\"]\n",arr[i][0],arr[i][26]);



	}
	fprintf(fp, "}\n");
	fclose(fp);

}

//=========================================================

fsm_again()
{
    int i,j,k;
    i=j=k=0;
    int state=0;
 int accept=0;
    int flag=0;
	FILE *fp;
	fp=fopen("psm.txt","w");
	fprintf(fp,"size=%d*%d:\n",20,27);


	for(i=0;i<10;i++)
	{

			if(arr[i][0]==-1)
				break;
        fprintf(fp,"%d %d %d:\n",arr[i][0],arr[i][1],arr[i][2]);
		//fprintf(fp,"%d -> %d [label=\"a\"]\n",arr[i][0],arr[i][1]);
		//fprintf(fp,"%d -> %d [label=\"b\"]\n",arr[i][0],arr[i][2]);


	}

	while(dfa_accept[i]!=-1)
	{
	    size_of_accept++;
		i++;
	}
		fprintf(fp,"sa=%d:\n",size_of_accept);
    //printf("%d\n",size_of_accept);
    i=0;
    while(dfa_accept[i]!=-1)
	{
		fprintf(fp,"%d:\n",dfa_accept[i]);
	//	printf("dfa accept=%d",dfa_accept[i]);
		i++;
	}
    char c[20];
    printf("\n\n put the string:\t");
    scanf("%s",c);

    for(i=0;i<size_of_accept;i++)
    {
   // printf("%d\t", dfa_accept[i]);

    }
i=0;
while(c[i]!='\0')
{
i++;
}   printf("\n");

i=0;

while(c[i]!='\0')
{printf("     ");
    if(c[i]=='a')
        state= arr[j][1];

    if(c[i]=='b')
        state =arr[j][2];
    if(c[i]=='c')
        state =arr[j][3];
    if(c[i]=='d')
        state =arr[j][4];
    if(c[i]=='e')
        state =arr[j][5];
    if(c[i]=='f')
        state =arr[j][6];
    if(c[i]=='g')
        state =arr[j][7];
    if(c[i]=='h')
        state =arr[j][8];
    if(c[i]=='i')
        state =arr[j][9];
    if(c[i]=='j')
        state =arr[j][10];
    if(c[i]=='k')
        state =arr[j][11];
    if(c[i]=='l')
        state =arr[j][12];
    if(c[i]=='m')
        state =arr[j][13];
    if(c[i]=='n')
        state =arr[j][14];
    if(c[i]=='o')
        state =arr[j][15];
    if(c[i]=='p')
        state =arr[j][16];
    if(c[i]=='q')
        state =arr[j][17];
    if(c[i]=='r')
        state =arr[j][18];
    if(c[i]=='s')
        state =arr[j][19];
    if(c[i]=='t')
        state =arr[j][20];
    if(c[i]=='u')
        state =arr[j][21];
    if(c[i]=='v')
        state =arr[j][22];
    if(c[i]=='w')
        state =arr[j][23];
    if(c[i]=='x')
        state =arr[j][24];
    if(c[i]=='y')
        state =arr[j][25];
    if(c[i]=='z')
        state =arr[j][26];


//printf("%d     ",state);
 //printf("%d",j);

i++;

for(k=0;k<20;k++)
{if(state ==arr[k][0])
        {

            j=k;break;

        }
if(state==-1)
{
    flag=1;
    printf("rejected is");
    break;
}
}


}
for(k=0;dfa_accept[k]!=-1;k++)
 if(dfa_accept[k]==state)
{
    accept=1;
    printf("\n\n\taccepted");
    break;
}
if(accept!=1)
    printf("rejected");


printf("\n\n%d",state);
	fprintf(fp, ";");
	fclose(fp);
}
//================================================================

void main()
{
	int t[20],v;
	int n=0,i=0,j,k;
   char in_str[20],postfix[20];
    char ch,temp;
    int x=0,y=0,pre;
    printf("Enter the infix regular expression :limit 20 char \t");
    scanf("%s",in_str);
    ch=in_str[x];
    while(ch!='\0')
    {
        //for operand
        if((ch>='a' && ch<='z') ||
(ch<='A' && ch>='Z') ||
(ch>='0' && ch<='9'))
               postfix[y++]=ch;
        //for '(' paranthesis
        else if(ch=='(')
            push1(ch);
        //for ')' parenthesis
        else if(ch==')')
        {
            temp=pop1();
            while(temp!='(')
            {
                postfix[y++]=temp;
                temp=pop1();
            }
          //  if(temp=='(')
               // pop();

        }
        //for operator
        else
        {
        //if the stack is empty or
        // the stack top element is '('
        //just push the operator in to the stack
            if (top1==-1 || stack1[top1]=='(')
                push1(ch);
            else
            {
                temp=stack1[top1];
                //check the precedence
                pre=check_pre(ch,temp);
                if(pre<0 )
                {
                    do{
                    postfix[y++]=pop1();
                    temp=stack1[top1];
}while(top1!=-1 && temp!='(' &&  (check_pre(ch,temp)<0));
                    push1(ch);
                }
                else
                {
                    push1(ch);
                }
            }
        }
        x++;
        ch=in_str[x];
    }
    while(top1!=-1)
    {
        postfix[y++]=pop1();
    }
    postfix[y]='\0';
    printf("Postfix string=%s\n",postfix);


	for(i=0;i<=25;i++)
		graph[i]=0;


    for(i=0;i<20;i++)
	    for(j=0;j<27;j++)
		  arr[i][j]=-1;


    for(i=0;i<20;i++)
    	dfa_accept[i]=-1;




	printf("\nPostfix Expression: %s",postfix);



	for(i=0;i<=20;i++)
	{
		if(postfix[i]=='a')
			graph[0]=1;
		if(postfix[i]=='b')
			graph[1]=1;
		if(postfix[i]=='c')
			graph[2]=1;
		if(postfix[i]=='d')
			graph[3]=1;
		if(postfix[i]=='e')
			graph[4]=1;
		if(postfix[i]=='f')
			graph[5]=1;
		if(postfix[i]=='g')
			graph[6]=1;
		if(postfix[i]=='h')
			graph[7]=1;
		if(postfix[i]=='i')
			graph[8]=1;
		if(postfix[i]=='j')
			graph[9]=1;
		if(postfix[i]=='k')
			graph[10]=1;
		if(postfix[i]=='l')
			graph[11]=1;
		if(postfix[i]=='m')
			graph[12]=1;
		if(postfix[i]=='n')
			graph[13]=1;
		if(postfix[i]=='o')
			graph[14]=1;
		if(postfix[i]=='p')
			graph[15]=1;
		if(postfix[i]=='q')
			graph[16]=1;
		if(postfix[i]=='r')
			graph[17]=1;
		if(postfix[i]=='s')
			graph[18]=1;
		if(postfix[i]=='t')
			graph[19]=1;
		if(postfix[i]=='u')
			graph[20]=1;
		if(postfix[i]=='v')
			graph[21]=1;
		if(postfix[i]=='w')
			graph[22]=1;
		if(postfix[i]=='x')
			graph[23]=1;
		if(postfix[i]=='y')
			graph[24]=1;
		if(postfix[i]=='z')
			graph[25]=1;

	}





	init_nfa_table();
	construct_nfa(postfix);



	disp_NFA();

printf("\ndfg\n");
	init_dfa_table();
	init_t(t);

	t[0]=initial_state;
	epsilon_closure(DFA[0].state,t);


	init_t(t);

	for(j=0,k=0; DFA[0].state[j]!=-1 ; j++)
	{
		v = DFA[0].state[j];

		if(NFA[v].a!=-1)
		{
			if(isPresent(t,NFA[v].a)==0)
				t[k++]=NFA[v].a;
		}
	}

	epsilon_closure(DFA[0].a,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].b!=-1)
		{
			if(isPresent(t,NFA[v].b)==0)
				t[k++]=NFA[v].b;
		}
	}
	epsilon_closure(DFA[0].b,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].c!=-1)
		{
			if(isPresent(t,NFA[v].c)==0)
				t[k++]=NFA[v].c;
		}
	}
	epsilon_closure(DFA[0].c,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].d!=-1)
		{
			if(isPresent(t,NFA[v].d)==0)
				t[k++]=NFA[v].d;
		}
	}
	epsilon_closure(DFA[0].d,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].e!=-1)
		{
			if(isPresent(t,NFA[v].e)==0)
				t[k++]=NFA[v].e;
		}
	}
	epsilon_closure(DFA[0].e,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].f!=-1)
		{
			if(isPresent(t,NFA[v].f)==0)
				t[k++]=NFA[v].f;
		}
	}
	epsilon_closure(DFA[0].f,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].g!=-1)
		{
			if(isPresent(t,NFA[v].g)==0)
				t[k++]=NFA[v].g;
		}
	}
	epsilon_closure(DFA[0].g,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].h!=-1)
		{
			if(isPresent(t,NFA[v].h)==0)
				t[k++]=NFA[v].h;
		}
	}
	epsilon_closure(DFA[0].h,t);

	init_t(t);
printf("%d\n",n);
	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].i!=-1)
		{
			if(isPresent(t,NFA[v].i)==0)
				t[k++]=NFA[v].i;
		}
	}
	epsilon_closure(DFA[0].i,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].j!=-1)
		{
			if(isPresent(t,NFA[v].j)==0)
				t[k++]=NFA[v].j;
		}
	}
	epsilon_closure(DFA[0].j,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].k!=-1)
		{
			if(isPresent(t,NFA[v].k)==0)
				t[k++]=NFA[v].k;
		}
	}
	epsilon_closure(DFA[0].k,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].l!=-1)
		{
			if(isPresent(t,NFA[v].l)==0)
				t[k++]=NFA[v].l;
		}
	}
	epsilon_closure(DFA[0].l,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].m!=-1)
		{
			if(isPresent(t,NFA[v].m)==0)
				t[k++]=NFA[v].m;
		}
	}
	epsilon_closure(DFA[0].m,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].n!=-1)
		{
			if(isPresent(t,NFA[v].n)==0)
				t[k++]=NFA[v].n;
		}
	}
	epsilon_closure(DFA[0].n,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].o!=-1)
		{
			if(isPresent(t,NFA[v].o)==0)
				t[k++]=NFA[v].o;
		}
	}
	epsilon_closure(DFA[0].o,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].p!=-1)
		{
			if(isPresent(t,NFA[v].p)==0)
				t[k++]=NFA[v].p;
		}
	}
	epsilon_closure(DFA[0].p,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].q!=-1)
		{
			if(isPresent(t,NFA[v].q)==0)
				t[k++]=NFA[v].q;
		}
	}
	epsilon_closure(DFA[0].q,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].r!=-1)
		{
			if(isPresent(t,NFA[v].r)==0)
				t[k++]=NFA[v].r;
		}
	}
	epsilon_closure(DFA[0].r,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].s!=-1)
		{
			if(isPresent(t,NFA[v].s)==0)
				t[k++]=NFA[v].s;
		}
	}
	epsilon_closure(DFA[0].s,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].t!=-1)
		{
			if(isPresent(t,NFA[v].t)==0)
				t[k++]=NFA[v].t;
		}
	}
	epsilon_closure(DFA[0].t,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].u!=-1)
		{
			if(isPresent(t,NFA[v].u)==0)
				t[k++]=NFA[v].u;
		}
	}
	epsilon_closure(DFA[0].u,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].v!=-1)
		{
			if(isPresent(t,NFA[v].v)==0)
				t[k++]=NFA[v].v;
		}
	}
	epsilon_closure(DFA[0].v,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].w!=-1)
		{
			if(isPresent(t,NFA[v].w)==0)
				t[k++]=NFA[v].w;
		}
	}
	epsilon_closure(DFA[0].w,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].x!=-1)
		{
			if(isPresent(t,NFA[v].x)==0)
				t[k++]=NFA[v].x;
		}
	}
	epsilon_closure(DFA[0].x,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].y!=-1)
		{
			if(isPresent(t,NFA[v].y)==0)
				t[k++]=NFA[v].y;
		}
	}
	epsilon_closure(DFA[0].y,t);

	init_t(t);

	for(j=0,k=0;DFA[0].state[j]!=-1;j++)
	{
		v = DFA[0].state[j];
		if(NFA[v].z!=-1)
		{
			if(isPresent(t,NFA[v].z)==0)
				t[k++]=NFA[v].z;
		}
	}
	epsilon_closure(DFA[0].z,t);
printf("1->\n");

	for(i=0;i<=n;i++)
	{
		if( search( n , DFA[i].a)==0 )
		{
			n++;
			copy(DFA[n].state,DFA[i].a);
printf("2->\n");
			init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			printf("%d\n",n);
			epsilon_closure(DFA[n].k,t);
		init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}

		if( search( n , DFA[i].b ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].b);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].c ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].c);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].d ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].d);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].e ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].e);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].f ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].f);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].g ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].g);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].h ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].h);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].i ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].i);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].j ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].j);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].k ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].k);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].l ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].l);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].m ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].m);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].n ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].n);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].o ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].o);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].p ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].p);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].q ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].q);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].r ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].r);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].s ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].s);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].t ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].t);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].u ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].u);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].v ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].v);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].w ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].w);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].x ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].x);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].y ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].y);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
		if( search( n , DFA[i].z ) ==0)
		{
			n++;
			copy(DFA[n].state,DFA[i].z);
init_t(t);

			for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
			{
				v = DFA[n].state[j];

				if(NFA[v].a!=-1)
				{
					if(isPresent(t,NFA[v].a)==0)
						t[k++]=NFA[v].a;
				}
			}

			epsilon_closure(DFA[n].a,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].b!=-1)
				{
					if(isPresent(t,NFA[v].b)==0)
						t[k++]=NFA[v].b;
				}
			}
			epsilon_closure(DFA[n].b,t);

			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].c!=-1)
				{
					if(isPresent(t,NFA[v].c)==0)
						t[k++]=NFA[v].c;
				}
			}
			epsilon_closure(DFA[n].c,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].d!=-1)
				{
					if(isPresent(t,NFA[v].d)==0)
						t[k++]=NFA[v].d;
				}
			}
			epsilon_closure(DFA[n].d,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].e!=-1)
				{
					if(isPresent(t,NFA[v].e)==0)
						t[k++]=NFA[v].e;
				}
			}
			epsilon_closure(DFA[n].e,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].f!=-1)
				{
					if(isPresent(t,NFA[v].f)==0)
						t[k++]=NFA[v].f;
				}
			}
			epsilon_closure(DFA[n].f,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].g!=-1)
				{
					if(isPresent(t,NFA[v].g)==0)
						t[k++]=NFA[v].g;
				}
			}
			epsilon_closure(DFA[n].g,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].h!=-1)
				{
					if(isPresent(t,NFA[v].h)==0)
						t[k++]=NFA[v].h;
				}
			}
			epsilon_closure(DFA[n].h,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].i!=-1)
				{
					if(isPresent(t,NFA[v].i)==0)
						t[k++]=NFA[v].i;
				}
			}
			epsilon_closure(DFA[n].i,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].j!=-1)
				{
					if(isPresent(t,NFA[v].j)==0)
						t[k++]=NFA[v].j;
				}
			}
			epsilon_closure(DFA[n].j,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].k!=-1)
				{
					if(isPresent(t,NFA[v].k)==0)
						t[k++]=NFA[v].k;
				}
			}
			epsilon_closure(DFA[n].k,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].l!=-1)
				{
					if(isPresent(t,NFA[v].l)==0)
						t[k++]=NFA[v].l;
				}
			}
			epsilon_closure(DFA[n].l,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].m!=-1)
				{
					if(isPresent(t,NFA[v].m)==0)
						t[k++]=NFA[v].m;
				}
			}
			epsilon_closure(DFA[n].m,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].n!=-1)
				{
					if(isPresent(t,NFA[v].n)==0)
						t[k++]=NFA[v].n;
				}
			}
			epsilon_closure(DFA[n].n,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].o!=-1)
				{
					if(isPresent(t,NFA[v].o)==0)
						t[k++]=NFA[v].o;
				}
			}
			epsilon_closure(DFA[n].o,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].p!=-1)
				{
					if(isPresent(t,NFA[v].p)==0)
						t[k++]=NFA[v].p;
				}
			}
			epsilon_closure(DFA[n].p,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].q!=-1)
				{
					if(isPresent(t,NFA[v].q)==0)
						t[k++]=NFA[v].q;
				}
			}
			epsilon_closure(DFA[n].q,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].r!=-1)
				{
					if(isPresent(t,NFA[v].r)==0)
						t[k++]=NFA[v].r;
				}
			}
			epsilon_closure(DFA[n].r,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].s!=-1)
				{
					if(isPresent(t,NFA[v].s)==0)
						t[k++]=NFA[v].s;
				}
			}
			epsilon_closure(DFA[n].s,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].t!=-1)
				{
					if(isPresent(t,NFA[v].t)==0)
						t[k++]=NFA[v].t;
				}
			}
			epsilon_closure(DFA[n].t,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].u!=-1)
				{
					if(isPresent(t,NFA[v].u)==0)
						t[k++]=NFA[v].u;
				}
			}
			epsilon_closure(DFA[n].u,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].v!=-1)
				{
					if(isPresent(t,NFA[v].v)==0)
						t[k++]=NFA[v].v;
				}
			}
			epsilon_closure(DFA[n].v,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].w!=-1)
				{
					if(isPresent(t,NFA[v].w)==0)
						t[k++]=NFA[v].w;
				}
			}
			epsilon_closure(DFA[n].w,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].x!=-1)
				{
					if(isPresent(t,NFA[v].x)==0)
						t[k++]=NFA[v].x;
				}
			}
			epsilon_closure(DFA[n].x,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].y!=-1)
				{
					if(isPresent(t,NFA[v].y)==0)
						t[k++]=NFA[v].y;
				}
			}
			epsilon_closure(DFA[n].y,t);
			init_t(t);

			for(j=0,k=0;DFA[n].state[j]!=-1;j++)
			{
				v = DFA[n].state[j];
				if(NFA[v].z!=-1)
				{
					if(isPresent(t,NFA[v].z)==0)
						t[k++]=NFA[v].z;
				}
			}
			epsilon_closure(DFA[n].z,t);

		}
printf("%d\n",n);
	}

	printf("\n\n\n\n\n");
	disp_DFA(n);
	printf("\n");
	printf("\n");
	printf("\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<26;j++)
			printf("%d\t\t",arr[i][j]);
		printf("\n");
	}
	//match(arr,10,3)

FILE *q;
q=fopen("D:/c.txt","wb");

	printf("\n%d",final_state);



fsm();
fsm_again();
}








