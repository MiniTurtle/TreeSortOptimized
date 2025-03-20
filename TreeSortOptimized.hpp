#include <vector>

struct ONode {
    int value;
    ONode* left;
    ONode* right;
};

static const size_t max_nodes = 10000000;
ONode mem[max_nodes];
ONode* stack[max_nodes];

void treesort_optimized(std::vector<int>& vec) {
    size_t len = vec.size();

    auto it = vec.data();

    ONode* last = nullptr;
    ONode** last_lr = nullptr;
    ONode* current;
    ONode* node = mem;
    node->value = *it;
    node->left = nullptr;
    node->right = nullptr;

    for (size_t i = 1; i < len; i++) {
        it++;
        node++;
        auto value = *it;
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
        
        current = mem;
        while (true) {
            if (value >= current->value) {
                last = current;
                last_lr = &current->right;
                current = current->right;
            } else {
                last = current;
                last_lr = &current->left;
                current = current->left;
            }

             if (!current) {
                *last_lr = node;
                break;
            }
        }
    }

    int* arr = vec.data();
    int idx = 0;
    int stack_top = -1;
    current = mem;

    while (stack_top != -1 || current) {
        while (current) {
            stack[++stack_top] = current;
            current = current->left;
        }

        current = stack[stack_top--];
        arr[idx++] = current->value;
        current = current->right;
    }
}