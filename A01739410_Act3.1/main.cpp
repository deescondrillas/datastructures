// Act 3.3 – 25 de octubre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 – Carlos Arturo Ferat Torres

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<class T>
class Node {
    public:
        // Constructor
        Node (T _data){
            data = _data;
            left = right = nullptr;
        }
        // Comparar nodos
        bool operator > (const Node<T>& otherNode) const {
            return data > otherNode.data;
        }
        // Comparar nodos
        bool operator < (const Node<T>& otherNode) const {
            return data < otherNode.data;
        }
    private:
        T data;
        Node<T>* left;
        Node<T>* right;

    template <class> friend class BST;
};

template<class T>
class BST {
    public:
        // Constructor
        BST (){root = nullptr;}

        // Insertar datos
        Node<T>* insert(T value, Node<T>* node = NULL){
            // Si el arbol esta vacio
            if (!root){
                root = new Node<T>(value);
                return root;
            }
            // Empieza en la raiz
            if (!node) node = root;
            // Inserta Izquierda
            if (value < node -> data){
                if(node -> left) insert(value, node -> left);
                else node -> left = new Node<T>(value);
            }
            // Inserta Derecha
            else if (value > node -> data){
                if(node -> right) insert(value, node -> right);
                else node -> right = new Node<T>(value);
            }
            return root;
        }

        // Eliminar datos
        void elimina(T value){
            elimina(value, root);
        }

        // Recorridos
        void traversal(int t){
            switch (t){
                case 1:
                    preOrden(root); // PreOrder
                    cout << endl;
                    break;
                case 2:
                    inOrden(root);  // InOrder
                    cout << endl;
                    break;
                case 3:
                    postOrden(root);    //PostOrder
                    cout << endl;
                    break;
                case 4:
                    levelOrder(root);   //Level by level
                    cout << endl;
                    break;
            }
        }

        // Altura
        int height(){
            return height(root);
        }

        // Ancestros
        void ancestors(T value){
            vector<T> an;
            ancestors(value, root, an);
            for (int i = an.size(); i > 0; i--)
                cout << an[i - 1] << " ";

            cout << endl;
        }

        // Nivel
        int whatlevelamI(T value){
            return whatlevelamI(value, root, 0);
        }

    private:
        Node<T>* root = NULL;

        // RID
        void preOrden(Node<T>* node){
            if(node){
                cout << node -> data << " ";
                preOrden(node -> left);
                preOrden(node -> right);
            }
        }

        // IRD
        void inOrden(Node<T>* node){
            if(node){
                inOrden(node -> left);
                cout << node -> data << " ";
                inOrden(node -> right);
            }
        }

        // IDR
        void postOrden(Node<T>* node){
            if (node){
                postOrden(node -> left);
                postOrden(node -> right);
                cout << node -> data << " ";
            }
        }

        // Por Nivel
        void levelOrder(Node<T>* node){
            queue<Node<T>*> a;
            a.push(root);
            while(!a.empty()){
                Node<T>* node = a.front();
                a.pop();
                cout << node -> data << " ";

                if(node -> left) a.push(node -> left);
                if(node -> right) a.push(node -> right);
            }
        }

        // Elimina
        Node<T>* elimina(T value, Node<T>* node){
            if(!node) return NULL;

            // Busca izquierda
            if (value < node -> data)
                node -> left = elimina(value, node -> left);

            // Busca dereca
            else if (value > node -> data)
                node -> right = elimina(value, node -> right);

            // Cuando lo encuentra
            else{
                // Si no hay hijos o solo uno
                if (!node -> left) return node -> right;
                if (!node -> right) return node -> left;

                // Si si tiene hijos
                Node<T>* na = node -> right;
                while (na && na -> left) na = na -> left;
                node -> data = na -> data;
                node -> right = elimina(na -> data, node -> right);
            }

            // Si borramos la raiz
            if (node == root && (node->left == nullptr && node->right == nullptr &&
                node->data == value)){
                    root = nullptr;
                }

            return node;
        }

        // Altura
        int height(Node<T>* node) {
            if (!node) return 0;
            int leftH = height(node->left);     // Altura izquierda
            int rightH = height(node->right);   // Altura derecha
            return 1 + max(leftH, rightH);      // Recorrido recursivo
        }

        // Ancestros
        bool ancestors(T value, Node<T>* node, vector<T>& an){
            if (!node) return false;
            if (node -> data == value) return true; //Encontro el valor

            // Busca el valor en los subarboles
            if(ancestors(value, node -> left, an) || ancestors(value, node -> right, an)){
                an.push_back(node -> data);    // Guarda su ancestro
                return true;
            }

            return false;   //No encontro el valor
        }

        // Nivel de un dato
        int whatlevelamI(T value, Node<T>* node, int level){
            if (!node) return -1;   // No lo encontro
            if (node-> data == value) return level; // Se encuentra al nivel

            int left = whatlevelamI(value, node -> left, level + 1);
            if (left != -1) return left;    // En el arbol izquierdo

            return whatlevelamI(value, node -> right, level + 1); //Arbol derecho
        }
};

int main(){
    BST<int> nums;
    int n; cin >> n;
    // Input
    for (int i = 0; i < n; i++){
        int temp; cin  >> temp;
        nums.insert(temp);
    }

    // Deletes
    int m; cin >> m;
    for (int i = 0; i < m; i++){
        int temp; cin >> temp;
        nums.elimina(temp);
    }

    // Recorridos
    for (int i : {1,2,3,4}) nums.traversal(i);
    // Altura del arbol
    cout << nums.height() << endl;

    // Ancestros
    int q; cin >> q;
    for (int i = 0; i < q; i++){
        int temp; cin >> temp;
        nums.ancestors(temp);
    }

    // Niveles
    int r; cin >> r;
    for (int i = 0; i < r; i++){
        int temp; cin >> temp;
        cout << nums.whatlevelamI(temp) << endl;
    }

    return 0;
}
