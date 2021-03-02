ArcNode* clean = p[i][j].first;

                    for(int i = 0;i < path[i][j].num;i++)
                    {
                        cout <<  path[i][j].num << endl;
                        cout << i << " " << j << endl;
                        ArcNode* last = clean;
                        clean = clean->next;
                        free(last);                    // 删除 j点 原路径
                    }