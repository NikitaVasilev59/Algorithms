#include <iostream>
struct Node {
	int value;
	struct Node* left;
	struct Node* right;
	unsigned height;
};
void fix_height(struct Node* a) {
	int height1 = a->left != nullptr ? a->left->height : 0;
	int height2 = a->right != nullptr ? a->right->height : 0;
	a->height = height1 > height2 ? height1 + 1 : height2 + 1;
}
void swap(struct Node* t1, struct Node* t2) {
	int temp = t1->value;
	t1->value = t2->value;
	t2->value = temp;
}
struct Node* small_left_rotation(struct Node* a) {
	struct Node* b = a->right;
	a->right = b->left;
	b->left = a;
	fix_height(a);
	fix_height(b);
	return b;
}
struct Node* small_right_rotation(struct Node* a) {
	struct Node* b = a->left;
	a->left = b->right;
	b->right = a;
	fix_height(a);
	fix_height(b);
	return b;
}
int height_diff(struct Node* a) {
	int height1 = a->left != nullptr ? a->left->height : 0;
	int height2 = a->right != nullptr ? a->right->height : 0;
	return height1 - height2;
}
struct Node* balance(struct Node* a) {
	if (height_diff(a) == -2) {
		if (height_diff(a->right) == 1) {
			a->right = small_right_rotation(a->right);
		}
		a = small_left_rotation(a);
		return a;
	}
	if (height_diff(a) == 2) {
		if (height_diff(a->left) == 1) {
			a->left = small_left_rotation(a->left);
		}
		a = small_right_rotation(a);
		return a;
	}
	return a;
}
bool Find(struct Node* node, int value) {
	if (node == nullptr) {
		return false;
	}
	if (node->value == value) {
		return true;
	}
	if (node->value > value) {
		return Find(node->left, value);
	}
	return Find(node->right, value);
}
struct Node* create_node(int value) {
	struct Node* new_node = new struct Node;
	new_node->value = value;
	new_node->left = new_node->right = nullptr;
	new_node->height = 1;
	return new_node;
}
void insert(struct Node** node, int value) {
	if ((*node) == nullptr) {
		(*node) = create_node(value);
		return;
	}
	else {
		if (value > (*node)->value) {
			insert(&((*node)->right), value);
		}
		else {
			insert(&((*node)->left), value);
		}
		*node = balance(*node);
	}
}
struct Node* erase(struct Node* root, int value) {
	if (root == nullptr) {
		return nullptr;
	}
	if (value > root->value) {
		root->right = erase(root->right, value);
	}
	else if (value < root->value) {
		root->left = erase(root->left, value);
	}
	else {
		if (root->right == nullptr || root->right == nullptr) {
			if (root->right == nullptr) {
				struct Node* need_return = root->left;
				delete root;
				need_return = balance(need_return);
				return need_return;
			}
			if (root->left == nullptr) {
				struct Node* need_return = root->right;
				delete root;
				need_return = balance(need_return);
				return need_return;
			}
		}
		else {
			struct Node* temp = root->right;
			struct Node* temp_parent = root;
			while (temp->left != nullptr) {
				temp_parent = temp;
				temp = temp->left;
			}
			swap(root, temp);
			if (temp->right == nullptr) {
				delete temp;
				if (temp_parent == root) {
					temp_parent->right = nullptr;
				}
				else {
					temp_parent->left = nullptr;
				}
			}
			else {
				if (temp_parent == root) {
					temp_parent->right = temp->right;
				}
				else {
					temp_parent->left = temp->right;
				}
				delete temp;
			}
		}
	}
	root = balance(root);
	return root;
}