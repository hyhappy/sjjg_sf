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

/**�����������ӽ�㣬�����ҵ�����λ�ü���**/
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

/**�������������������༴�������
   ʹ���˵ݹ�ķ������ɶ��׶�����Ч�ʲ���
   ������ջʵ�ַǵݹ飺
   ˼·���ý����ջ�����������������㣬ѭ��ǰ�����
         �����ջ�����ʸý�㣬���ҽ�������ҽ�㣬ѭ��ǰ�����
         �����ջ��ֱ��ջ�ղ����޽��ɷ���**/
void BinaryTree::OutByOrder(BinaryNode *p)
{
	if(p!=NULL)
	{
		OutByOrder(p->left);
		cout<<p->data<<'\t';

		OutByOrder(p->right);
	}
}


/**���غ�̽��
    ����������������������������
    �����������������������ڵ��Ҹ��ڵ�**/
BinaryNode* BinaryTree::BackNode(BinaryNode *p)
{
    BinaryNode *q;
    if(p->right!=NULL)//��������
    {
        p=p->right;
        while(p)
        {
            q=p;
            p=p->left;
        }
    }
    else//��������
    {
        while(p)//ѭ�������丸�ڵ�
        {
            if(p==root)//���ڵ㣬����
            {
                cout<<"this is root,no backnode"<<endl;
                q=p;
                break;
            }
            if(p==p->parent->left)//���󸸽ڵ�
            {
                q=p->parent;
                break;
            }
            else
                p=p->parent;//���󸸽ڵ�
        }

    }
    return q;
}

/**ɾ��������˼·����backnode�������غ�̽��
                    Ȼ�����̽�㽻������󽫸ý��delete**/
void BinaryTree::DelNode(int dt)
{
    BinaryNode *p=root,*q;
    while(p)//���Ҹý��
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
    q=BackNode(p);//�õ���̽��
    if(p==root)     //����Ǹ�����Ҫ����ָ����
        root=q;
    if(q=q->parent->left)   //����̽����֮ǰ���ڵ��ϵ���
        q->parent->left=NULL;
    else
        q->parent->right=NULL;
    q->left=p->left;    //��̽�����ɾ����㸸�ӹ�ϵ����
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
