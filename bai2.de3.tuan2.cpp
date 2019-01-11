#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
using namespace std;
struct nut {
	char nd[80];
	nut *sau,*truoc;
};
typedef nut Node;
Node *dau,*dau1,*dau2;

void khoitao (Node*&dau)
{
	dau=NULL;
}
void nhapvb(Node *&dau)
{
	Node *p,*q;
	char ndt[80];
	int i=1;
	do{
		printf("\n Nhap noi dung %d: ",i);
		fflush(stdin);
		gets(ndt);
			if(strcmp(ndt,"\0")!=0)
			{
				p= new Node;
				strcpy(p->nd,ndt);
				p->sau=NULL;
				p->truoc=NULL;
				if(dau==NULL)
					dau=p;
				else{
				q->sau=p;
				p->truoc=q;
				}
				q=p;
				i=i+1;
			}
	}
	while (strcmp(ndt,"\0")!=0);
}

void duyetdq(Node *dau)
{
	if(dau!=NULL)
	{
		printf("\n %s",dau->nd);
		duyetdq(dau->sau);
	}
}
//-------------cau 1 - in dong vb tu i -> j-------
void Inij(Node *dau, int i,int j)
{
	int k;
	Node *p;
	k=1;p=dau;
	//Tim nut i
	while (k<i && p!=NULL)
	{
		p=p->sau;
		k=k+1;
	}
	if (p==NULL) printf ("\n Khong co noi dung can in \n");
	else 
	// Co nut i,p la dia chi nut i
	for(k=i;k<=j;k++)
	{
		printf("\n %s",p->nd);
		p=p->sau;
			if(p==NULL) break;
	}
}

//------------Cau 3--chen dong tu nhap vao cuoi doan 
void Chendong(Node*&dau,Node*&dau1,char s[80]){ //tim vi tri cuoi cua vb t, chen s vao = cach moc t vao 
		dau1=NULL;
		Node *p,*d;
		p =dau;
	    	while(p->sau!=NULL)
		    p=p->sau;// tim vi tri cuoi cung cua vb goc can chen
		  if(p==NULL) printf("\n Khong chen dc \n");
		  
		  else{	// chen dong s vao cuoi vb
			d= new Node;  // luu s vao 1 nut
		   strcpy(d->nd,s);
		   d->truoc=NULL;
		   d->sau=NULL;
		   if(dau1==NULL)
		   	dau1=d; //gan d cho dau1
		   	
		   // noi cuoi vb vs dau1 vb
		   p->sau= dau1;
		   dau1->truoc=p;
		   dau1->sau=NULL;
		
		}
}

//---cau 3 mo rong--chep dong i-j vao sau dong k
void chepij(Node*&dau, int i, int j,Node*&dau2,int k){ 

	Node *p,*q,*t,*cf,*u;
	Node *a,*b;
	int v;  //tim vt k
		  
			v=1;a=dau;
			while(v<k && a!=NULL){
			a=a->sau;
			v=v+1;
			}
			if(a!=NULL){
	
		if(j>=i){ //tim dong i
		p=dau;	int dem = 1;
		while(p!=NULL && dem<i){
		  p=p->sau;
		  dem=dem+1;
		}
				
		if(p!=NULL){  // p!=NULL la da tim dc i, sau do tim tiep dong j
			dem =i+1;
			q=p;
			while(q!=NULL&&dem<j){
				q=q->sau;
				dem+=1;
			}
			if(q!=NULL){ // q!=NULL la da tim dc j => tao ds moi luu vb tu i->j
			  u=dau2;
			 while(p!=q->sau){
		 		
					dau2=NULL;
					int d = i;
				//for(int d=i; d<j+1; d++){
				while(d <= j){
			
				if(p!=NULL ){		
			 	t= new Node;
			 	strcpy(t->nd,p->nd);
			 	t->sau=NULL;
			 	t->truoc=NULL;
			 	
			 	if(dau2==NULL)
			 	   dau2=t;
			 	 else
				 		 	 
				  u->sau=t;
			
				  t->truoc=u;
				  u=t;
				  p=p->sau;
				  cout<<"\n chay lan "<<d;
				  d++;
				
	}
			
		}		
	}
	}	else
			printf("\n Ko tim duoc dong j = %d \n", j);
			
	}  else
			printf("\n Ko tim duoc dong i = %d \n",i);			
	}  else 
			printf("\n Ban nen nhap i < j \n");
	
		// chen
			cf=dau2;
	    	while(cf->sau!=NULL)
		    cf=cf->sau;
			t=a->sau;
			a->sau=dau2;
			dau2->truoc=p;
			cf->sau=t;
			t->truoc=cf;
//
//			cf = a->sau; 
//			a->sau= t; 
//			dau2->truoc=a; 
//			t->sau=cf; 
//			cf->truoc=t;
	
			}
				else
				 printf("\n Khong chen dc vi ko tim thay vi tri k = %d \n", k);
											
			
}
//-----------Cau 4-- xoa dong tu i -> j-

void Xoadong (Node *dau,int i)
{
	Node *t,*p,*q;
	int k=1; p=dau;
	//Tim nut i
	while(k<i && p!=NULL)
	{
		p=p->sau;
		k=k+1;
	}
	
	//PHAI VIET CHO CA 3 TH CUA P:
	if(p!=NULL)
	{ //p la dia chi dong i
		//TH1: p la nut dau
	if(p==dau)
	{
		dau=dau->sau;
		dau->truoc=NULL;
		delete p;
	}
	else 
	if (p->sau!=NULL)
	//TH2: p khong la nut cuoi cung
	{
		t=p->truoc;
		q=p->sau;
		t->sau=q;
		q->truoc=t;
		delete p;
	}
	else //TH3: p la nut cuoi
	{
		t=p->truoc;
		t->sau=NULL;
		delete p;
	}
}
}
void Xoadongij (Node *&dau,int i,int j)
{ int k;
	for(k=i;k<=j;k++) // dem so dong// xoa tu i den j tuc la xoa j-i+1 lan dong i.
	//vd: xoa 3-5 => xoa 5-3+1=3 dong 3; vi khi xoa dong 3 lan 1 thi dong 4 se? tro thanh dong 3, d5 -> d4; xoa d3 lan 2, d4(d5 cu) -> d3;
		Xoadong(dau,i);
}

int main()
{
	int i, j,k;
	char s[80];
//cau1:	
	khoitao(dau);
	nhapvb(dau);
	printf("\n Duyet van ban de quy \n");
	duyetdq(dau);
	printf("\nNhap vi tri i  va j: ");
	scanf("%d%d",&i,&j);
//cau2:	
	printf("\n In van ban tu %d den %d :",i,j);
	Inij(dau,i,j);
//cau 3:	
//	printf("\nNhap noi dung can chen : \n");
//	fflush(stdin);
//	gets(s);
//	printf("\nChen dong tu nhap vao cuoi doan vb: \n");
//	Chendong(dau,dau1,s);
//	duyetdq(dau);
//cau3 mo rong: chep doan vb i->j sau do chen vao sau vi tri k
	printf("\nNhap vi tri k can chen sau do: ");
	scanf("%d",&k);
	printf("\nChep dong %d den %d:",i,j);
	chepij(dau,i,j,dau2,k);
	printf("\n Duyet dau 2: \n");
	duyetdq(dau2);
	
	printf("\n Duyet dau : \n");
	duyetdq(dau);
	
	printf("\n Duyet dau 2: \n");
	duyetdq(dau2);
//cau 4:	
//	printf("\nXoa van ban tu %d den %d :",i,j);	
//	Xoadongij(dau,i,j);
//	duyetdq(dau);
	
	getch();
	return 0;
}
