const fs = require("fs");


class Product {
    constructor(id, name, category, price, quantity) {
        this.id = id;
        this.name = name;
        this.category = category;
        this.price = price;
        this.quantity = quantity;
    }

    display() {
        console.log(`
ID: ${this.id}
Name: ${this.name}
Category: ${this.category}
Price: $${this.price}
Quantity: ${this.quantity}
-----------------------
        `);
    }
}



class ProductCatalog {

    constructor() {
        this.products = [];
        this.load();
    }


    addProduct(product) {
        this.products.push(product);
        console.log("Product added!");
    }


    displayProducts() {

        if(this.products.length === 0) {
            console.log("Catalog empty");
            return;
        }

        this.products.forEach(product => {
            product.display();
        });
    }


    searchProduct(keyword) {

        let results = this.products.filter(product =>
            product.name.toLowerCase().includes(keyword.toLowerCase()) ||
            product.category.toLowerCase().includes(keyword.toLowerCase())
        );


        if(results.length === 0) {
            console.log("Product not found");
            return;
        }


        results.forEach(product => product.display());
    }



    removeProduct(id) {

        let before = this.products.length;


        this.products = this.products.filter(product =>
            product.id !== id
        );


        if(this.products.length < before)
            console.log("Product removed");
        else
            console.log("Product not found");
    }



    updateQuantity(id, amount) {

        let product = this.products.find(
            product => product.id === id
        );


        if(product) {

            product.quantity = amount;
            console.log("Inventory updated");

        } else {

            console.log("Product not found");
        }
    }



    save() {

        fs.writeFileSync(
            "products.json",
            JSON.stringify(this.products,null,2)
        );

        console.log("Saved!");
    }



    load() {

        if(fs.existsSync("products.json")) {

            let data = fs.readFileSync(
                "products.json",
                "utf8"
            );

            this.products = JSON.parse(data);
        }
    }

}




// Application

const catalog = new ProductCatalog();


catalog.addProduct(
    new Product(
        1,
        "Handmade Necklace",
        "Jewelry",
        49.99,
        15
    )
);


catalog.addProduct(
    new Product(
        2,
        "Oil Painting",
        "Art",
        150,
        3
    )
);



console.log("\nALL PRODUCTS");
catalog.displayProducts();



console.log("\nSEARCH JEWELRY");
catalog.searchProduct("Jewelry");



console.log("\nUPDATE STOCK");
catalog.updateQuantity(1,25);



console.log("\nREMOVE PRODUCT");
catalog.removeProduct(2);



catalog.save();
