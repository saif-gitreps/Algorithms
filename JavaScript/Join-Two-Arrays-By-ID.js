// solution 1

/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */

var join = function(arr1, arr2) {
    let ans = arr1.concat(arr2);
    // this is like a visited obj, id value map.
    let merged = {};

    ans.forEach((item) => {
        if(!merged[item.id]){
            merged[item.id] = {...item};
        }
        else{
            /*
              if the ID already exists in the merged object, it means that there is another object with the same ID. 
              In this case, we perform a merge of the properties. We update the existing object in merged by copying its properties (...merged[id]) and 
              then overriding them with the properties of the current object (...obj). 
              This ensures that the properties from arr2 take precedence over arr1 during the merging process.

              so this works for the case of arr2 values overriding arr1 because , arr1 values will be first put in the merged object.
              first we will merge the stuffs from arr1, then second param ...item will override any values of arr1 with the same id.
            */
            merged[item.id] = {...merged[item.id], ...item};
        }
    });

    // this removes the id and just puts the value into the array, note that the id is already in the values, cuz we used spread operator
    // and the merged was used like a map.
    ans = Object.values(merged);
    ans.sort((a,b) => a.id - b.id);

    return ans;
};
