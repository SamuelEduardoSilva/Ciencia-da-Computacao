#include <windows.h>
#include <gl/glut.h>
#include<bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;
bool flag = true;

GLdouble ox=0.0,oy=0.0,oz=0.0;

void DrawString(void *font,const char s[],float x,float y)
{
	unsigned int i;
	glRasterPos2f(x,y);
	for(i=0;i<strlen(s);i++)
	{
		glutBitmapCharacter(font,s[i]);
	}
}
struct vetor
{
    int a,b;
};
struct ponto
{
    double x,y;
    bool operator < (const ponto & p) const {  return (x == p.x)? y<p.y : x <p.x ; }
};
struct reta
{
    int a,b;
};

struct aresta
{
    double w;
    int p,f;

    bool operator < (const aresta &q)const
    {
        return w < q.w;
    }
};

struct estado
{
    double w;
    int p,f;

    bool operator < (const estado &q)const
    {
        return w > q.w;
    }

};

double cross( const ponto & O, const ponto &A, const ponto &B) {
	return (A.x - O.x) * (B.y - O.y) - (A.y -O.y) * (B.x-O.x);
}
vector<ponto> convex_hull(vector<ponto> P)
{
    int n = P.size(), k = 0;
    vector<ponto> H(2*n);

    // Sort points lexicographically
    sort(P.begin(), P.end());

    // Build lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    // Build upper hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    H.resize(k);
    return H;
}




vector<ponto>pontos;
vector<ponto>pontos2;
vector<vector<pair<int,double> > >grafo;
vector<aresta>grafo2;


int memo[16][1<<16];
int ini;
int pd(int pos, int mask)
{

	if(__builtin_popcount(mask) == grafo.size())
	{
		return grafo[pos][ini].second;
	}

	if(memo[pos][mask] != -1) return memo[pos][mask];

	int ans = oo;
	for(int j = 0 ; j < (int)grafo[pos].size() ;j++)
	{
	    int i = grafo[pos][j].first;
	    int cust = grafo[pos][j].second;
		if(pos != i)
		{
			if(!((mask >> i) & 1))
			{

				ans = min(ans, pd(i, mask | (1 << i)) + cust);

			}
		}
	}

	return memo[pos][mask] = ans;
}

vector<int>res;

void rec(int pos, int mask)
{
	int ans = oo;
	int melhorVet;
	if(__builtin_popcount(mask) == grafo.size())
		return;
	for(int j = 0 ; j < (int)grafo[pos].size() ;j++)
	{
	    int i = grafo[pos][j].first;
		if(!((mask >> i) & 1))
		{
			if(ans > pd(i, mask | (1 << i)))
			{
				ans = pd(i, mask | (1 << i));
				melhorVet = i;
			}
		}
	}
	res.push_back(melhorVet);
	rec(melhorVet, mask | (1 << melhorVet));
}


void GeraPonto()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
   // glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(10);
    glBegin(GL_POINTS);
    for(int i=0; i<(int)pontos.size(); i++)
    {
            glVertex2i(pontos[i].x,pontos[i].y);
            if(flag)
            glVertex2i(pontos2[i].x,pontos2[i].y);
    }
    glEnd();
    glFlush();
   // glClear(GL_COLOR_BUFFER_BIT);
}
void geraLinha(int x1,int y1,int x2,int y2, int op)
 {
     // glClear(GL_COLOR_BUFFER_BIT);

      if(op)
      {
          glLineWidth(6.0);
          glColor3f(0.0f, 1.0f, 0.0f);
      }
      else
      {
          glLineWidth(3.0);
          glColor3f(0.0f, 0.0f, 1.0f);
      }

      glBegin(GL_LINES);
      glVertex2i(x1,y1);
        glVertex2i(x2,y2);
       glEnd();
       glFlush();
  }

void geraGrafo()
{
    grafo.assign((int)pontos.size(), vector<pair<int,double> >());
    grafo2.clear();
    for(int i = 0 ; i < (int)grafo.size() ; i++)
    {
        for(int j = i +1 ; j < (int)grafo.size(); j++)
        {
            double dist = hypot(pontos[i].x - pontos[j].x, pontos[i].y - pontos[j].y);
            geraLinha(pontos[i].x, pontos[i].y, pontos[j].x, pontos[j].y,0);
            if(flag)
            geraLinha(pontos2[i].x, pontos2[i].y, pontos2[j].x, pontos2[j].y,0);
            grafo[i].push_back(make_pair(j,dist));
            grafo[j].push_back(make_pair(i,dist));
            aresta q;
            q.f = i;
            q.p = j;
            dist = hypot(pontos2[i].x - pontos2[j].x, pontos2[i].y - pontos2[j].y);
            q.w = dist;
            grafo2.push_back(q);
        }
    }
    GeraPonto();
}

vector<int>p;

int findset(int u)
{
    if(p[u] == u)
        return u;
    return p[u] = findset(p[u]);
}

void unionset(int x, int y)
{
    x = findset(x);
    y = findset(y);
    p[y] = x;
}
void animaLinha(ponto a, ponto b)
{
            vetor aux;

            aux.a = a.x - b.x;
            aux.b = a.y - b.y;

            double div1 = (double)aux.a/1000.0;
            double div2 = (double)aux.b/1000.0;

            double cur1 = 0;
            double cur2 = 0;
            for(int i = 0 ; i < 1000; i++)
            {

                geraLinha(b.x+cur1, b.y+cur2, b.x+cur1+div1, b.y+cur2+div2,1);
                cur1+=div1;
                cur2+=div2;
                Sleep(0.3);
            }
}

void kruskal()
{

    p.clear();

    for(int i = 0 ; i < (int)pontos.size(); i++) p.push_back(i);

    sort(grafo2.begin(), grafo2.end());
    double MST = 0;
    for(int i = 0 ; i < (int)grafo2.size(); i++)
    {
        int a = grafo2[i].f;
        int b = grafo2[i].p;
        double w = grafo2[i].w;
        if(findset(a) != findset(b))
        {
            MST += w;
            unionset(a,b);
            animaLinha(pontos2[a],pontos2[b]);
        }
    }
    string x  = "Arvore Geradora Minima do Grafo = ";

    stringstream aux ; aux << MST;
    string y;
    aux >> y;
    x += y;
    x += " Pixels";

    DrawString(GLUT_BITMAP_HELVETICA_18, x.c_str(), 700, 50);
}
vector<int>visitados;
priority_queue<estado >pq;

void process(int u)
{
    visitados[u] = 1;
    for(int i = 0 ; i < (int)grafo[u].size(); i++)
    {
        int v = grafo[u][i].first;
        double w = grafo[u][i].second;
        if(!visitados[v])
        {
            estado q;
            q.w = w;
            q.p = u;
            q.f = v;
             pq.push(q);
        }
    }
}



void prim()
{
    process(0);
    double MST = 0;
    while(!pq.empty())
    {
        int v = pq.top().f;
        int u = pq.top().p;
        double w = pq.top().w;
        pq.pop();

        if(!visitados[v])
        {

            animaLinha(pontos[v], pontos[u]);

            MST += w;
           // Sleep(100);
            process(v);

        }
    }
    string x  = "Arvore Geradora Minima do Grafo = ";

    stringstream aux ; aux << MST;
    string y;
    aux >> y;
    x += y;
    x += " Pixels";

    DrawString(GLUT_BITMAP_HELVETICA_18, x.c_str(), 50,50);

}

void desenhaConvex(vector<ponto>P)
{
    double ch = 0;


    for(int i = 0 ; i < (int)P.size()-1; i++)
    {

        animaLinha(P[i+1],P[i]);
        ch += hypot(P[i].x - P[i+1].x, P[i].y - P[i+1].y);
    }

    string x  = "Convex Hull dos pontos = ";

    stringstream aux ; aux << ch;
    string y;
    aux >> y;
    x += y;
    x += " Pixels";
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawString(GLUT_BITMAP_HELVETICA_18, x.c_str(), 350,50);
}

void desenhaTSP()
{

    animaLinha(pontos[res[0]],pontos[0]);

    for(int i = 0 ; i < (int)res.size()-1; i++)
    {

         animaLinha(pontos[res[i+1]],pontos[res[i]]);

    }
     animaLinha(pontos[0], pontos[res[res.size()-1]]);

      string x  = "Percurso do caixeiro = ";
        int resp = pd(0,1);
        stringstream aux ; aux << resp;
        string y;
        aux >> y;
        x += y;
        x += " Pixels";
        cout << "eoq" << endl;
        glColor3f(1.0f, 1.0f, 1.0f);

        DrawString(GLUT_BITMAP_HELVETICA_18, x.c_str(), 350,50);
}

void Teclado (unsigned char tecla, int x, int y)
{

   if(tecla == 32) /// Espaço
   {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0f, 1.0f, 0.0f);
        visitados.assign(pontos.size(),0);
        DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "Kruskal", 850,550);
        DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "Prim", 250, 550);
        GeraPonto();
        flag = true;
           geraGrafo();
           flag = true;
           GeraPonto();
           prim();
           GeraPonto();
           kruskal();
           GeraPonto();

    }
    else if(tecla == 'c')
    {
        glColor3f(1.0f, 1.0f, 0.0f);

        flag = false;
        glClear(GL_COLOR_BUFFER_BIT);
        DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "Envoltoria Convexa", 500,550);

        GeraPonto();

        desenhaConvex(convex_hull(pontos));

        GeraPonto();

    }
    else if(tecla == 't')
    {

         glColor3f(1.0f, 1.0f, 0.0f);

        flag = false;
        glClear(GL_COLOR_BUFFER_BIT);
        DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "Caixeiro Viajante", 500,550);
        GeraPonto();
        geraGrafo();
        memset(memo, -1, sizeof memo);
        ini = 0;
        pd(0,1);
        res.clear();
        rec(0,1);

        desenhaTSP();

        GeraPonto();

    }
    else if(tecla == 'l')
    {
         glClear(GL_COLOR_BUFFER_BIT);
         DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "Digite novos pontos", 500,550);
        pontos.clear();
        pontos2.clear();
        visitados.assign(10000, 0);
        grafo.clear();


    }
    else if(tecla == 27) /// Esc
    {
        exit(0);
    }

}

void Mouse(int button,int state,int x,int y)
{
    flag = false;
    GLint viewport[4];
    GLdouble modelview[16],projection[16];
    GLfloat wx=x,wy,wz;
    if(state!=GLUT_DOWN)
        return;
    if(button==GLUT_RIGHT_BUTTON)
        exit(0);
    glGetIntegerv(GL_VIEWPORT,viewport);
    y=viewport[3]-y;
    wy=y;
    glGetDoublev(GL_MODELVIEW_MATRIX,modelview);
    glGetDoublev(GL_PROJECTION_MATRIX,projection);
    glReadPixels(x,y,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,&wz);
    gluUnProject(wx,wy,wz,modelview,projection,viewport,&ox,&oy,&oz);
    ponto h; h.x = ox; h.y = oy;
    pontos.push_back(h);
    h.x += 550;
    pontos2.push_back(h);
    glutDisplayFunc(GeraPonto);
    glutPostRedisplay();
}
void Inicializa (void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "Digite novos pontos", 500,550);
}
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    if(h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        gluOrtho2D (0.0f, 600.0f, 0.0f, 600.0f*h/w);
    else
        gluOrtho2D (0.0f, 600.0f*w/h, 0.0f, 600.0f);
}
int main()
{
    visitados.assign(10000, 0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Minimum Spanning Tree | Convex Hull | TSP");
    glutMouseFunc(Mouse);
    glutDisplayFunc(GeraPonto);
    glutKeyboardFunc (Teclado);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    glutMainLoop();
}
