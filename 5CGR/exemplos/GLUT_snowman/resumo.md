# Resumo do Snowman com GLUT

São criadas respectivamente 4 funções principais posteriormente chamadas em `main()`:

```c
// Change viewing volume and viewport.  Called when window is resized  
(1) void ChangeSize(int w, int h)  

// This function does any needed initialization on the rendering context.  Here it sets up and initializes the lighting for the scene.  
(2) void SetupRC()

(3) void SpecialKeys(int key, int x, int y)

// Called to draw scene  
(4) void RenderScene(void)
```

(1) é uma função fixa para qualquer cena, ao menos que realmente seja necessário alterar ela de alguma forma. (2) gerencia a iluminação da cena, portanto não define o comportamento da figura em si. (3) diz respeito aos comantos realizados pelo usuário durante a cena, pelo teclado por exemplo, e as variáveis de rotação da figura devem ser declaradas globalmente. Já (4) contém a figura em sí, logo o intuito principal do código.





