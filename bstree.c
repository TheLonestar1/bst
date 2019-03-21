#include"bstree.h"

struct bstree *bstree_create(int key, char *value) {
	struct  bstree *node;
	node = malloc(sizeof(*node));
	if(node != NULL) {
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

void bstree_add(struct bstree *tree, int key, char  *value) {
	if (tree != NULL) {
		struct bstree *parent, *node;
			while (tree != NULL) {
			parent = tree;
			if (key < tree->key)
				tree = tree->left;
			else if (key > tree->key)
				tree = tree->right;
			else return;
		}
	
		node = bstree_create(key, value);
			if (key < parent->key)
				parent->left = node;
			else
				parent->right = node;
	}
}
struct bstree *bstree_lookup(struct bstree *tree, int key) {
	
	while(tree != NULL){
		if(key == tree->key){
			return tree;
		}
		else if(key < tree->key){
			tree = tree->left;
		}
		else {
			tree = tree->right;
		}
	
	}
	return tree;
}
struct bstree *bstree_delete(struct bstree *tree, int key) {
	
	struct bstree *deleter, *changer, *parent;
	if(tree->key == key) {
		free(tree);
		return NULL;
	}
	parent = tree;
	if(key > parent->key) {
		deleter = parent->right;
		while(deleter != NULL){
			deleter = parent->right;
			if(deleter->key == key) {
				if((deleter->right == NULL) && (deleter->left == NULL)){
					parent->right = NULL;
					free(deleter);
					break;
				}
				else if((deleter->right != NULL) && (deleter->left == NULL)){
					parent->right = deleter->right;
					free(deleter);
					break;
				}
				else if((deleter->right == NULL) && (deleter->left != NULL)){
					parent->right = deleter->left;
					free(deleter);
					break;
				}	
				else if((deleter->right != NULL) && (deleter->left != NULL)){
					changer = bstree_min(deleter);
					parent->right = changer;
					free(deleter);
					break;
				}
				
			} else {
				parent = parent->right;
			}	
		}	
	} if(key < parent->key) {
		deleter = parent->left;
		while(deleter != NULL){
			deleter = parent->left;
			if(deleter->key == key) {	
				if((deleter->right == NULL) && (deleter->left == NULL)){
					parent->left = NULL;
					free(deleter);
					break;
				}
				else if((deleter->right != NULL) && (deleter->left == NULL)){
					parent->left = deleter->right;
					free(deleter);
					break;
				}
				else if((deleter->right == NULL) && (deleter->left != NULL)){
					parent->left = deleter->left;
					free(deleter);
					break;
				}	
				else if((deleter->right != NULL) && (deleter->left != NULL)){
					changer = bstree_min(deleter);
					parent->left = changer;
					free(deleter);
					break;
				}
			} else {
				parent = parent->left;
			}	
		}	
	}
	return tree;
} 
	

struct bstree *bstree_min(struct bstree *tree) {
	
	if(tree == NULL) return NULL;
	
	while(tree->left != NULL) 
		tree = tree->left;
	
	return tree;
}
struct bstree *bstree_max(struct bstree *tree) {
	
	if(tree == NULL) return NULL;
	while(tree->right != NULL) 
		tree = tree->right;
	return tree;
}
