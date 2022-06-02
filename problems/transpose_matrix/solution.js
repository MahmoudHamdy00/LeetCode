/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var transpose = function(matrix) {
    var n=matrix.length
    var m=matrix[0].length
    var ret=[]
    for(var i=0;i<m;++i){
        var row=[]
        for(var j =0;j<n;++j){
            row.push(matrix[j][i])
        }
        ret.push(row)
    }
    return ret
};