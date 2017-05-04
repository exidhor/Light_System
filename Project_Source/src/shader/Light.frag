// ils permettent de traiter le rendu de chaque pixel qui
// s'affichera à l'écran. Ces derniers offrent une grande
// flexibilité dans le domaine du rendu 3D

//uniform sampler2D texture;

void main()
{
    // récupère le pixel dans la texture
    //vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    // et multiplication avec la couleur pour obtenir le pixel final
    //gl_FragColor = gl_Color * pixel;

    vec4 customColor = gl_Color;

    customColor.w = normalize(gl_FragCoord).x;

    gl_FragColor = customColor;
    //gl_FragColor = gl_Color;
}