#include"bstree.h"



int main(){
	
	struct bstree *tree, *node;
tree = bstree_create("12", "Koala");
bstree_add(tree, "4","Flamingo");
bstree_add(tree, "14", "Fox");
node = bstree_lookup(tree, "4");
printf("Found value for key %s: %s\n", node->key, node->value);
node = bstree_min(tree);
printf("Minimal key: %s, value: %s\n", node->key, node->value);
tree =  bstree_delete(tree, "4");
node = bstree_min(tree);
printf("Minimal key: %s, value: %s\n", node->key, node->value);
return 0;
}
