namespace NxxCSharp
{
    public class SyntaxToken
    {
        public SyntaxToken(string? text, SyntaxKind kind)
        {
            Text = text;
            Kind = kind;
        }

        public string? Text { get; set; }
        public SyntaxKind Kind { get; set; }
    }
}