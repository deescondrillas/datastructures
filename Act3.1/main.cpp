// Act 3.1 – 25 de octubre, 2025

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
        // Comparar nodos                       | O(1)
        bool operator > (const Node<T>& otherNode) const {
            return data > otherNode.data;
        }
        // Comparar nodos                       | O(1)
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

        // Insertar datos                       | promedio de O(log₂n)
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

        // Eliminar datos                           | promedio de O(log₂n)
        void elimina(T value){
            elimina(value, root);
        }

        // Recorridos                               | O(n)
        void traversal(int t){
            switch (t){
                case 1:
                    preOrden(root); // PreOrden     | O(n)
                    cout << endl;
                    break;
                case 2:
                    inOrden(root);  // InOrden      | O(n)
                    cout << endl;
                    break;
                case 3:
                    postOrden(root);    //PostOrden | O(n)
                    cout << endl;
                    break;
                case 4:
                    levelByLevel(root); //Por nivel | O(n)
                    cout << endl;
                    break;
            }
        }

        // Altura                           | O(n)
        int height(){
            return height(root);
        }

        // Ancestros                        | promedio de O(log₂n)
        void ancestors(T value){
            vector<T> an;
            ancestors(value, root, an);
            //Imrpime de la raiz hacia abajo
            for (int i = an.size(); i > 0; i--)
                cout << an[i - 1] << " ";
            cout << endl;
        }

        // Nivel                            | promedio de O(log₂n)
        int whatlevelamI(T value){
            return whatlevelamI(value, root, 0);
        }

    private:
        Node<T>* root = NULL;

        // Imprime recorrido en preOrden        | O(n)
        void preOrden(Node<T>* node){
            if(node){
                cout << node -> data << " ";
                preOrden(node -> left);
                preOrden(node -> right);
            }
        }

        // Imprime recorrido en inOrden         | O(n)
        void inOrden(Node<T>* node){
            if(node){
                inOrden(node -> left);
                cout << node -> data << " ";
                inOrden(node -> right);
            }
        }

        // Imprim recoriddo en postOrden        | O(n)
        void postOrden(Node<T>* node){
            if (node){
                postOrden(node -> left);
                postOrden(node -> right);
                cout << node -> data << " ";
            }
        }

        // Imprime recorrido por Nivel          | O(n)
        void levelByLevel(Node<T>* node){
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

        // Elimina                              | promedio de O(log₂n)
        Node<T>* elimina(T value, Node<T>* node){
            if(!node) return NULL;

            // Busca izquierda
            if (value < node -> data)
                node -> left = elimina(value, node -> left);

            // Busca derecha
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
                node->data == value)) root = nullptr;

            return node;
        }

        // Altura                               | O(n)
        int height(Node<T>* node) {
            if (!node) return 0;
            int leftH = height(node->left);     // Altura izquierda
            int rightH = height(node->right);   // Altura derecha
            return 1 + max(leftH, rightH);      // Retorna rama mayor
        }

        // Ancestros                            | O(n)
        bool ancestors(T value, Node<T>* node, vector<T>& an){
            if (!node) return false;

            // Busca el valor en los subarboles
            if (value < node -> data){
                if (ancestors(value, node -> left, an)){
                    an.push_back(node -> data);
                    return true;
                }
            }
            else if (value > node -> data){
                if (ancestors(value, node -> right, an)){
                    an.push_back(node -> data);
                    return true;
                }
            }
            else return true;   //Encontro el valor
            return false;       //No encontro el valor
        }

        // Nivel de un dato                     | promedio de O(log₂n)
        int whatlevelamI(T value, Node<T>* node, int level){
            if (!node) return -1;
            if (node-> data == value) return level; // Se encuentra al nivel
            //Busca en los subarboles
            if(value < node -> data){
                return whatlevelamI(value, node -> left, level + 1);
            }
            else return whatlevelamI(value, node -> right, level + 1);
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Estructura de datos y variables
    BST<int> nums;
    int temp, n, m, q, r;

    // Input del arbol                          | O(n log₂n)
    cin >> n;
    for (int i = 0; i < n; i++){
        cin  >> temp;
        nums.insert(temp);
    }

    // Elimina m nodos del arbol                | O(m log₂n)
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> temp;
        nums.elimina(temp);
    }

    // Recorridos                               | O(n)
    for (int i : {1,2,3,4}) nums.traversal(i);

    // Altura del arbol                         | O(n)
    cout << nums.height() << endl;

    // Ancestros                                | O(q log₂n)
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> temp;
        nums.ancestors(temp);
    }

    // Niveles                                  | O(r log₂n)
    cin >> r;
    for (int i = 0; i < r; i++){
        cin >> temp;
        cout << nums.whatlevelamI(temp) << endl;
    }

    return 0;
}
