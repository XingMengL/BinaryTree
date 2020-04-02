#include "BinTree.h"
#include "Queue.h"
//前序遍历   根 左 右

BTNode* BuyNewNode(DataType val)
{
	BTNode* NewpRoot = (BTNode*)malloc(sizeof(BTNode));
	if(NULL == NewpRoot)
	{
		assert(0);
		return NULL;

	}
	NewpRoot->val = val;
	NewpRoot->pLeft = NULL;
	NewpRoot->pRintt = NULL;
	
	return NewpRoot;
}
BTNode* CreatBinTree(int * array, int size,int* index,DataType invalid )
{
	BTNode* pRoot = NULL;
	if( *index < size && array[*index] != invalid)
	{
		//创建根节点
		pRoot = BuyNewNode(array[*index]);
		//递归创建左子树
		++(*index);
		pRoot->pLeft = CreatBinTree(array,size,index,invalid);
		//递归创建右子树
		++(*index);
		pRoot->pRintt = CreatBinTree(array,size,index,invalid);

	
	
	}

	return pRoot;

}
void PreOrder(BTNode * pRoot)
{
	if(pRoot)
	{
		printf("%d ",pRoot->val);
		PreOrder(pRoot->pLeft);
		PreOrder(pRoot->pRintt);
	}
}
//中序遍历  左 根  右
void InOrder(BTNode * pRoot)
{
	if(pRoot)
	{   
		InOrder(pRoot->pLeft);
		printf("%d ",pRoot->val);
		InOrder(pRoot->pRintt);
	}
}

//后序遍历 左 右 根
void PostOrder(BTNode * pRoot)
{
	if(pRoot)
	{   
		 PostOrder(pRoot->pLeft);
		 printf("%d ",pRoot->val);
		 PostOrder(pRoot->pRintt);
	}
}
//获取二叉树中节点的个数
/*int count = 0;
int GetNodeCount(BTNode * pRoot)
{

	if(pRoot)
	{
		count++;
		GetNodeCount(pRoot->pLeft);
		GetNodeCount(pRoot->pRintt);
	}

	return count;

}*/
//获取二叉树中节点的个数
int GetNodeCount(BTNode * pRoot)
{
	if(NULL == pRoot)
	  return 0;
	else
	{
		return GetNodeCount(pRoot->pLeft)+GetNodeCount(pRoot->pRintt) + 1; 
	}
}


//获取二叉树中叶子节点的个数
int GetLeafCount(BTNode * pRoot)
{
	if(NULL == pRoot)
		return 0;
	if(NULL == pRoot->pLeft && NULL == pRoot->pRintt)
		return 1;
	return GetLeafCount(pRoot->pLeft)+ GetLeafCount(pRoot->pRintt);
}

//获取第k层中节点的个数
int GetKLevelCount(BTNode * pRoot,int k)
{
	if(NULL == pRoot || k <= 0)
		return 0;
	if(k == 1)
		return 1;

		return GetKLevelCount(pRoot->pLeft,k-1)+GetKLevelCount(pRoot->pRintt,k-1);	
}

//获取二叉树的高度
int GetHeigh(BTNode * pRoot)
{
	int L = 0;//左子树高度
	int R = 0;//右子树的高度
	if(NULL == pRoot)
		return 0;
	L = GetHeigh(pRoot->pLeft);
	R = GetHeigh(pRoot->pRintt);

	return L>R?L+1:R+1;
}
//返回x在树中所对应的节点
BTNode * Find(BTNode * pRoot , DataType x)
{
	BTNode * pNode = NULL;
	if(NULL == pRoot)
		return NULL;

	if(x == pRoot->val)
		return pRoot;
	if((pNode == Find(pRoot->pLeft,x)) || (pNode ==Find(pRoot->pRintt,x) ))
		return pRoot;
	return NULL;
	//不能按照这种方式进行返回，因为逻辑运算的结果是一个bool类型 只有‘0’‘1’
	//return Find(pRoot->pLeft,x) || Find(pRoot->pRintt,x);
}
//获取pNode的双亲
BTNode * GetParent(BTNode * pRoot,BTNode * pNode)
{
	BTNode * parent = NULL;
	if(pNode == pRoot || NULL == pRoot || NULL == pNode)
		return NULL;
	if(pRoot->pLeft == pNode || pRoot->pRintt == pNode)
		return pRoot;
	if((parent == GetParent(pRoot->pLeft,pNode)) || (parent == GetParent(pRoot->pRintt,pNode)))
		return parent;
	return NULL;

	//return GetParent(pRoot->pLeft,pNode) || GetParent(pRoot->pRintt,pNode);

}
void LevelOrder(BTNode * pRoot)//层序遍历
{
	Queue q;
	InitQueue(&q);
	if(NULL == pRoot)
		return;
	PushQueue(&q,pRoot);//根节点入队
	while(!EmptyQueue(&q))
	{
		BTNode * cur = FrontQueue(&q);//保存队列中第一个元素
		PopQueue(&q);//出队
		printf("%d ",cur->val);

		if(cur->pLeft)
			PushQueue(&q,cur->pLeft);
		if(cur->pRintt)
			PushQueue(&q,cur->pRintt);
	
	}
	printf("\n");


}

void BinTreeTest()
{
	int array[] ={1,2,3,-1,-1,-1,4,5,-1,-1,6};
	int index = 0;
	CreatBinTree(array,sizeof(array)/sizeof(array[0]),&index,-1);

}
