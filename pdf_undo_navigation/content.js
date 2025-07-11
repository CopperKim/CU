// content.js
(() => {
  // 간단한 상태 스택
  const navStack = [];
  let lastHash = location.hash || '';         // 초기 위치 저장
  let isProgrammaticJump = false;             // undo 중복 push 방지

  const MAX_STACK = 100;                      // 스택 메모리 제한

  /** hash 변화 감지: 내부 링크 · Thumbnails 클릭 시 */
  function onHashChange() {
    if (isProgrammaticJump) {
      // undo 로 인한 이동이면 기록 X
      isProgrammaticJump = false;
      return;
    }
    const current = location.hash;
    if (current !== lastHash && lastHash !== '') {
      navStack.push(lastHash);
      if (navStack.length > MAX_STACK) navStack.shift(); // 오래된 항목 삭제
    }
    lastHash = current;
  }

  /** 되돌리기 실행 */
  function undoNav() {
    const prev = navStack.pop();
    if (prev !== undefined) {
      isProgrammaticJump = true;      // push 되지 않도록 플래그
      location.hash = prev || '';     // ''이면 첫 페이지(보통 1)로 이동
    }
  }

  /** 키보드 단축키 백업(컨텐츠 스크립트만으로도 작동) */
  function onKeyDown(ev) {
    const isUndoKey =
      (ev.ctrlKey || ev.metaKey) && !ev.shiftKey && !ev.altKey && ev.key.toLowerCase() === 'z';
    if (isUndoKey) {
      // PDF 안에서는 기본 undo 의미가 없으므로 가로채기
      ev.preventDefault();
      undoNav();
    }
  }

  /** background → content 메시지 (chrome.commands 전파) */
  chrome.runtime.onMessage.addListener((msg, _sender, _respond) => {
    if (msg?.type === 'UNDO_PDF_NAV') undoNav();
  });

  // 리스너 설치
  window.addEventListener('hashchange', onHashChange, true);
  window.addEventListener('keydown', onKeyDown, true);
})();
