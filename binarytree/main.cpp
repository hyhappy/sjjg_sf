/*************************************************************************
    > File Name: BinaryTree.cpp
    > Author: Tuqi
    > Mail: Tuuuqi@163.com
    > Created Time: Mon 14 Mar 2016 08:12:20 PM CST
    > func: some op of binarytree
        eg: add,delete,backnode,out..
 ************************************************************************/

#include<iostream>
using namespace std;
class BinaryNode
{
	public:
		int data;
		BinaryNode *left;
		BinaryNode *right;
		BinaryNode *parent;

		BinaryNode(int dt)
		{
			data=dt;
			left=right=parent=NULL;
		}
};
class BinaryTree
{
	public:
		BinaryNode *root;
		int number;

		BinaryTree(){
			number=0;
			root=NULL;
		}

		void AddNode(int dt);
		void DelNode(int dt);
		void OutByOrder(BinaryNode *p);
		void Search(int dt);
		void MaxData();
		void MinData();
		BinaryNode *BackNode(BinaryNode *p);
};

/**向二叉树中添加结点，遍历找到最终位置即可**/
void BinaryTree::AddNode(int dt)
{
	BinaryNode *p,*q;
	p = new BinaryNode(dt);
	q =root;
	if(root==NULL)
		root=p;
	else{
		while(q)
		{
			if(dt<q->data)
			{
				if(q->left==NULL)
				{
					q->left=p;
					p->parent=q;
					return;
				}
				else{
					q=q->left;
				}
			}
			else
			{
				if(q->right==NULL)
				{
					q->right=p;
					p->parent=q;
					return;
				}
				else{
					q=q->right;
				}
			}
		}

	}
}

/**中序遍历输出二叉树，亦即按序输出
   使用了递归的方法，可读易懂但是效率不高
   可以用栈实现非递归：
   思路：该结点入栈，有左结点则跳至左结点，循环前面过程
         无则出栈，访问该结点，有右结点跳至右结点，循环前面过程
         无则出栈，直到栈空并且无结点可访问**/
void BinaryTree::OutByOrder(BinaryNode *p)
{
	if(p!=NULL)
	{
		OutByOrder(p->left);
		cout<<p->data<<'\t';

		OutByOrder(p->right);
	}
}


/**返回后继结点
    有右子树：返回右子树的最左结点
    无右子树：返回其最左祖宗的右父节点**/
BinaryNode* BinaryTree::BackNode(BinaryNode *p)
{
    BinaryNode *q;
    if(p->right!=NULL)//有右子树
    {
        p=p->right;
        while(p)
        {
            q=p;
            p=p->left;
        }
    }
    else//无右子树
    {
        while(p)//循环查找其父节点
        {
            if(p==root)//根节点，无需
            {
                cout<<"this is root,no backnode"<<endl;
                q=p;
                break;
            }
            if(p==p->parent->left)//无左父节点
            {
                q=p->parent;
                break;
            }
            else
                p=p->parent;//有左父节点
        }

    }
    return q;
}

/**删除操作，思路：用backnode函数返回后继结点
                    然后与后继结点交换，最后将该结点delete**/
void BinaryTree::DelNode(int dt)
{
    BinaryNode *p=root,*q;
    while(p)//查找该结点
    {
        if(p->data==dt)
        {
            break;
        }
        else if(p->data<dt&&p->right!=NULL)
            p=p->right;
        else if(p->data>dt&&p->left!=NULL)
            p=p->left;
        else
        {
            cout<<"no this node"<<endl;
            return;
        }
    }
    q=BackNode(p);//得到后继结点
    if(p==root)     //如果是跟，需要重新指定跟
        root=q;
    if(q=q->parent->left)   //将后继结点与之前父节点关系解除
        q->parent->left=NULL;
    else
        q->parent->right=NULL;
    q->left=p->left;    //后继结点与待删除结点父子关系交接
    q->right=p->right;
    q->parent=p->parent;
    delete p;
}

int main()
{
	int num,dt;
	BinaryTree BT;
	cout<<"0. quit"\
        <<endl<<"1. add data"\
        <<endl<<"2. del data"\
        <<endl<<"3. out data"\
        <<endl;
	while(1)
    {
        cout<<"please input num of func:"<<endl;
        cin>>num;
        switch(num)
        {
            case 0:
                return 0;
                break;
            case 1:
                cout<<"input data:";
                cin>>dt;
                BT.AddNode(dt);
                break;
            case 2:
                cout<<"input data:";
                cin>>dt;
                BT.DelNode(dt);
                break;
            case 3:
                BT.OutByOrder(BT.root);
                break;
            default:
                break;
        }
    }
	return 0;
}
