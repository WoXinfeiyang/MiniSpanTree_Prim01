#include <iostream>
#include<stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
��С������Prime�㷨
2014-12-25 23:12 
Prim�㷨����˼��: 
1����ͼN = { V, E }��ѡ��ĳһ����u0 ���б�ǣ�֮
��ѡ�����������ľ�����СȨֵ�ı�(u0, v)��������
��v ���б��
2��������һ�����㱻��ǣ�����һ������δ����ǵĸ�
������ѡ��Ȩֵ��С�ı�(u, v),����δ��ǵĶ����
�б��
3����˼�����ȥ��ֱ��ͼ�е����ж��㶼�����Ϊֹ
*/

//�궨������� 
#define Infinity 65535
//�궨����󶨵��� 
#define MaxVertexs 20

typedef struct 
{
 	   int arc[MaxVertexs][MaxVertexs];//������ 
 	   int numVertexs;//������ 
	   int numEdges;//���� 
}MGraph;


void CreateGraph(MGraph* G)
{
 	 int i=0,j=0;
 	 G->numVertexs=9;
 	 G->numEdges=15;
	
	
	 for(i=0;i<G->numVertexs;i++)
	 {
	 	for(j=0;j<G->numVertexs;j++)
	 	{
			if(i==j)
				G->arc[i][j]=0;
			else
		 		G->arc[i][j]=Infinity;
		}							  							 
	 }
	//�����������������ε�ֵ 
	G->arc[0][1]=10;
	G->arc[0][5]=11; 
	G->arc[1][2]=18; 
	G->arc[1][8]=12; 
	G->arc[1][6]=16; 
	G->arc[2][8]=8; 
	G->arc[2][3]=22; 
	G->arc[3][8]=21; 
	//G->arc[3][6]=24; 
	G->arc[3][7]=16;
	G->arc[3][4]=20;
	G->arc[4][7]=7; 
	G->arc[4][5]=26; 
	G->arc[5][6]=17; 
	G->arc[6][7]=19;
	
	//ͨ���������ξ���ȷ���������ξ���
	for(i=0;i<G->numVertexs;i++)
	{
		for(j=i;j<G->numVertexs;j++)
			G->arc[j][i]=G->arc[i][j];	
	}
		 
}
//��������ķ�ʽ���ͼ 
void MGraphPrint(MGraph G)
{
	for(int i=0;i<G.numVertexs;i++)
	{
		for(int j=0;j<G.numVertexs;j++)
			printf("%7d,",G.arc[i][j]);
		printf("\n");	
	}	
} 

//��С������Prim�㷨 
/*
G---��������洢����ͨͼ��sv---������С����������ʼ�� 
*/ 
void MiniSpanTree_Prim(MGraph *G,int sv)
{
	int i=0,j=0;
	
	/*cost�������ڴ���Ѽ�����С�������Ķ��㼯��������������δ������С�������������γɱߵ�Ȩֵ */
	int Cost[MaxVertexs];
	int Point[MaxVertexs];//����Ѿ�������С�����������±�
	int Mark[MaxVertexs];//������״̬��0---δ����ǹ��Ķ��㣬1---��ǹ��Ķ��� 
	
	 
	if((sv>-1)&&(sv<G->numVertexs))//������С��������ʼ��ĺϷ��Լ�� 
	{
		for(i=0;i<G->numVertexs;i++)//��ʼ������ 
		{
			Cost[i]=G->arc[sv][i];
			Point[i]=sv;
			Mark[i]=0;	
		}
		
		Mark[sv]=1;//�Ӷ���sv��ʼ������С�����������ʼĬ�϶���sv�Ѽ��뵽��С������
		
		//������С������ 
		for(i=0;i<G->numVertexs;i++)
		{
			int min=Infinity;
			int index;//��ű�Ȩֵ��С�����±� 
			
			//�����Ѽ��뵽��С�������ж���������δ���뵽�������Ķ���֮�����γ�Ȩֵ 
			for(j=0;j<G->numVertexs;j++)
			{
				if((!Mark[j])&&(Cost[j]<min))
				{
					min=Cost[j];
					index=j;	
				}
			}
			
			if(index>-1)
			{
				Mark[index]=1;//�����ҵĶ�����б��
				printf("[%d,%d]=%d\n",Point[index],index,Cost[index]);			
			}
			/*���ող��ҵ��Ķ�������ǰ�Ѽ��뵽��С�������Ķ��㿴��һ�����壬����˵����һ�����ϣ�����ȷ����������еĶ���������δ�ڼ����ж������γɱߵ���СȨֵ*/
			for(j=0;j<G->numVertexs;j++)
			{
				if((!Mark[j])&&(G->arc[index][j]<Cost[j]))
				{
					Cost[j]=G->arc[index][j];
					Point[j]=index;//ȷ������δ�ڼ����ж���j����С���������㼯�ж�Ӧ�Ķ��� 
				}	
			}				
		}		
	}	
}

int main(int argc, char *argv[]) 
{
	MGraph G;
	CreateGraph(&G);

	MGraphPrint(G);
	
	printf("��С������Ϊ:\n");
	MiniSpanTree_Prim(&G,1);
	return 0;
}
