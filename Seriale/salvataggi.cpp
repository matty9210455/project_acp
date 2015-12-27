//elemento da spostare
//col indice riga pos indice posizione elemento nel vector
void BLUE::update(int col, int pos,int  N_row){
    if(Blue[col-1][pos]<N_row){
        Blue[col-1][pos]+=Blue[col-1][pos];
        return;
    }else{
        Blue[col-1].insert(Blue[col-1].begin(),1);//migliorare
        auto last=Blue[col-1].end()-1;
        Blue[col-1].erase(last);
        return;
    }

}



//elemento da spostare
//row indice riga pos indice posizione elemento nel vector
void RED::update(int row, int pos, int N_col){
    if(Red[row-1][pos]<N_col) {
        Red[row-1][pos]+=Red[row-1][pos];
        return;
    }else{
        Red[row-1].insert(Red[row-1].begin(),1);//migliorare
        auto last=Red[row-1].end()-1;
        Red[row-1].erase(last);
        return;
    }
}
