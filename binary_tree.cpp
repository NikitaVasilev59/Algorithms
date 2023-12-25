#include <iostream>
struct Node {
	int value;
	struct Node* left;
	struct Node* right;
	Node(int v) {
		value = v;
		left = nullptr;
		right = nullptr;
	}
	Node() : Node(0) {
	}
};
void swap(struct Node* t1, struct Node* t2) {
	int temp = t1->value;
	t1->value = t2->value;
	t2->value = temp;
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
	struct Node* new_node = new struct Node(value);
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
	}
}
struct Node* erase(struct Node* root, int value) {
	if (root == nullptr) {
		return nullptr;
	}
	if (value > root->value) {
		root->right = erase(root->right, value);
		return nullptr;
	}
	else if (value < root->value) {
		root->left = erase(root->right, value);
		return nullptr;
	}
	if (root->right == nullptr) {
		struct Node* need_return = root->left;
		delete root;
		return need_return;
	}
	if (root->left == nullptr) {
		struct Node* need_return = root->right;
		delete root;
		return need_return;
	}
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
	return root;
}
void Traverse(struct Node* node) {
	if (node == nullptr) {
		return;
	}
	Traverse(node->left);
	std::cout << node->value << ' ';
	Traverse(node->right);
}