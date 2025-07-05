// background.js
chrome.commands.onCommand.addListener((command) => {
  if (command === 'undo-pdf-nav') {
    // 현재(포커스) 탭의 모든 frame에 'undo' 메시지 전파
    chrome.tabs.query({ active: true, currentWindow: true }, ([tab]) => {
      if (!tab?.id) return;
      chrome.tabs.sendMessage(tab.id, { type: 'UNDO_PDF_NAV' });
    });
  }
});
