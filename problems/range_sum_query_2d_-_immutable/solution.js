/**
 * @param {number[][]} matrix
 */
var NumMatrix = function(matrix) {
    for(var i=0;i<matrix.length ;++i)
        for(var j =1; j<matrix[i].length ;++j)
            matrix[i][j]+=matrix[i][j-1];
    
    for(var j =0; j<matrix[0].length ;++j)
        for(var i=1;i<matrix.length ;++i)
            matrix[i][j]+=matrix[i-1][j];
    this.matrix=matrix
};

/** 
 * @param {number} row1 
 * @param {number} col1 
 * @param {number} row2 
 * @param {number} col2
 * @return {number}
 */
NumMatrix.prototype.sumRegion = function(row1, col1, row2, col2) {
    var ret=this.matrix[row2][col2];
    if(row1-1>=0)ret-=this.matrix[row1-1][col2];    
    if(col1-1>=0)ret-=this.matrix[row2][col1-1];
    if(row1-1>=0&&col1-1>=0)ret+=this.matrix[row1-1][col1-1];
    return ret;
};

/** 
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */