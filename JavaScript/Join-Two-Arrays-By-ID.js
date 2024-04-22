// solution 1.

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

// Solution 2.

/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */

var join = function(arr1, arr2) {
    const mp = new Map();
    
    for(const item of arr1) {
        mp.set(item.id, item);
    }
    
    for(const item of arr2){
        if(!mp.has(item.id)){
            mp.set(item.id, item);
        }
        else{

            /*
                In JavaScript, objects are passed by reference. When you retrieve an object from the map mp using mp.get(item.id) 
                and store it in the variable prevItem,
                prevItem holds a reference to the same object that is stored in the map.
            */
            const prevItem = mp.get(item.id);
            for(const key of Object.keys(item)){
                prevItem[key] = item[key];
            }
        }

    }

    const res = new Array();
    for(let key of mp.keys()){ 
        res.push(mp.get(key));
    }
    return res.sort((a,b)=>a.id-b.id);
};


// solution 3 
// What i had in mind but the confusion was how to deal with overlapping arr2 object.

/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */

var join = function(arr1, arr2) {
    arr1.sort((a,b) => a.id - b.id);
    arr2.sort((a,b) => a.id - b.id);
    let i = 0;
    let j = 0;

    let ans = [];

    while(i < arr1.length && j < arr2.length){
        if(arr1[i].id == arr2[j].id){

            // guess I learned how to overlap two objects. Where keys that are common will get replaced by the second param.
            // the uncommon keys from the first params will stay and the uncommon from the second params will stay as well.
            ans.push({
                ...arr1[i],
                ...arr2[j]
            });
            i ++;
            j ++;
        } 
        else if (arr1[i].id < arr2[j].id){
            ans.push({
                ...arr1[i]
            });
            i ++;
        }
        else{
            ans.push({
                ...arr2[j]
            });
            j++;
        }   
    }

     while(i < arr1.length) {
        ans.push({
            ...arr1[i++]
        });
    }

    while(j < arr2.length) {
        ans.push({
            ...arr2[j++]
        })
    }

    return ans;
};
