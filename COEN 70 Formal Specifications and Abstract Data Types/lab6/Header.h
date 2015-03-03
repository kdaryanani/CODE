RBNode *rotateRight(RBNode* X){
    
    RBNode *edit = NULL;
    RBNode *edit = X->left();
    X->set_left(edit->right());
    edit->set_right(x);
    return edit;
}

RBNode* rotateLeft(RBNode* X){
    
    RBNode *edit = NULL;
    RBNode *edit = X->right();
    X->set_right(edit->left());
    edit->set_selft(x);
    return edit;
    
}