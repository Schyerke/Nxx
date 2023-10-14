namespace NxxCSharp
{
    public class Lexer
    {
        private readonly string _text;
        private int _index;

        public Lexer(string text)
        {
            _text = text;
        }

        private char Current
        {
            get
            {
                if(_index < _text.Length)
                {
                    return _text[_index];
                }
                return '\0';
            }
        }

        private void Advance()
        {
            if(_index < _text.Length)
            {
                _index++;
            }
        }

        public SyntaxToken Lex()
        {
            if(Current == '\0')
            {
                return new SyntaxToken(null, SyntaxKind.EOF);
            }

            if (char.IsWhiteSpace(Current))
            {
                while (char.IsWhiteSpace(Current))
                {
                    Advance();
                }
            }

            if (char.IsDigit(Current))
            {
                int start = _index;
                while (char.IsDigit(Current))
                {
                    Advance();
                }
                int end = _index - start;
                string text = _text.Substring(start, end);

                return new SyntaxToken(text, SyntaxKind.Number);
            }

            switch (Current)
            {
                case '+':
                    Advance();
                    return new SyntaxToken("+", SyntaxKind.PlusToken);
                case '-':
                    Advance();
                    return new SyntaxToken("-", SyntaxKind.MinusToken);
                case '*':
                    Advance();
                    return new SyntaxToken("*", SyntaxKind.StarToken);
                case '/':
                    Advance();
                    return new SyntaxToken("/", SyntaxKind.SlashToken);
            }
            
            return new SyntaxToken(null, SyntaxKind.BadToken);
        }
    }
}