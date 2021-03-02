void CreateTree(BiTree *t)
{
    char ch;
    scanf("%c", &ch);
     
    if(ch == '#')
    {
        *t = NULL;
    }
    else
    {
        (*t) = (BiTree)malloc(sizeof(BitNode));
        if((*t) == NULL)
        {
            return;
        }
        (*t)->data = ch;
        CreateTree(&((*t)->lchild));
        CreateTree(&((*t)->rchild));
    }
}