int calcBinaryTreeLevel(BiTree T){
	if(T==NULL)
		return 0;
	else{
		//分解
		BiTree lchild = T->lchild;
		BiTree rchild = T->rchild;
		//解决
		int lLevel = calcBinaryTreeLevel(lchild) + 1;
		int rLevel = calcBinaryTreeLevel(rchild) + 1;
		//合并
		return max(lchild,rchild);
	} 
}
