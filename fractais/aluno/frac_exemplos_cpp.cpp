#include <lib/pen.h>

void triangulo (Pen &p, int lado, int rotacao){
//    while(lado > 20){
//        p.walk(lado);
//        p.right (60);
//        lado -=10;
//    }
    if(lado < 10)
        return;

    for(int i = 0; i < 3 ; i++){
        p.setThickness(2);
        p.walk(lado);
        p.right(-120 * rotacao);
        triangulo(p,lado/2,rotacao);
    }
    p.setColor(rand()%255, rand()%255, rand()%255);
    lado += 5;

//    p.setColor(255,0,0);
//    while(lado <=400){
//        lado +=10;
//        p.left(60);
//        p.walk(-lado);

//    }

}

void trigo (Pen &p, int lado){
    if(lado < 1)
        return;

    p.setColor(230,175,75);

    int angulo = 40;

    for (int i = 0; i < 4; i++) {
        p.setThickness(2);
        p.walk(lado);
        p.right(angulo);
        trigo(p,lado/3);
        p.left(2 * angulo);
        trigo(p,lado/3);
        p.right(angulo);
    }

    p.walk(-lado*4);

}

void fractal_trigo(Pen &p){
    p.setHeading(90);
    p.setXY(400,600);
    trigo(p,100);
}

void gelo(Pen &p, int tam){
    if(tam < 1){
        return;
    }

        for(int i = 0; i < 5; i++){
            p.setThickness(2);
            p.setColor(0,250,255);
            p.walk(tam);
            gelo(p,tam / 2.7);
            p.walk(-tam);
            p.right(72);
        }

}void fractal_gelo(Pen &p){
    p.setHeading(90);
    p.setXY(400,300);
    gelo(p,200);
}


void linha(Pen &p, int lado, int rotacao){
    if(lado < 1)
        return;
    //p.setColor(rand()%255, rand()%255, rand()%255);

//    p.walk(lado);
//    p.right(90 * rotacao);
    //linha(p, lado - 5, 1);

    p.setColor(rand()%255, rand()%255, rand()%255);
    linha(p, lado - 5, -1);
}

void fractal(){
    Pen p(800, 600);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(50, 590);

    //faz o pincel apontar pra direita
    p.setHeading(0);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(30);

    p.setBackColor(255 ,255 ,255);
   // p.circle(200);
    //linha(p, 100, -1);
    //espera clicar no botao de fechar
    //triangulo(p,600,1);
    //fractal_trigo(p);
    fractal_gelo(p);
    p.wait();
}

int main(){
    fractal();
    return 0;
}
